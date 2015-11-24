#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QTime>

#include "keithleywindow.h"
#include "ui_keithleywindow.h"

KeithleyWindow::KeithleyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KeithleyWindow)
{
    // Setup the UI including all Signal/Slots
    ui->setupUi(this);
}

KeithleyWindow::~KeithleyWindow()
{
    delete ui;
}

/*!
 * Select the beam off file
 */
void KeithleyWindow::newBeamOffFile()
{
    beamOffFilename_ = QFileDialog::getSaveFileName(this, "Please choose a BEAM OFF file name");
    ui->lblCurrentBeamOffFile_->setText( beamOffFilename_ );
}

/*!
 * Select the beam on file
 */
void KeithleyWindow::newBeamOnFile()
{
    beamOnFilename_ = QFileDialog::getSaveFileName(this, "Please choose a BEAM ON file name");
    ui->lblCurrentBeamOnFile_->setText( beamOnFilename_ );
}

/*!
 * Record a Beam off measurement
 */
void KeithleyWindow::beamOffMeasurement()
{
    genericBeamMeasurement( beamOffFilename_ );
}

/*!
 * Record a beam on measurement
 */
void KeithleyWindow::beamOnMeasurement()
{
    genericBeamMeasurement( beamOnFilename_ );
}

/*!
 * Record generic measurement
 */
void KeithleyWindow::genericBeamMeasurement( const QString &fname )
{
    // Open the file
    QFile outf{fname};
    if (!outf.open(QIODevice::Append))
    {
        QMessageBox msg;
        msg.setText("Could not open beam file");
        return;
    }

    // Create a text stream to write out everything
    QTextStream outstr(&outf);

    // Store the time
    outstr << QTime::currentTime().toString("hh:mm:ss") << ", ";

    // Write out Fluence and Measurement
    outstr << ui->spnFluence_->value() << "e" << ui->spnFluenceExp_->value() <<
              ", " << QString::fromStdString( kdev_.forward_voltage_measurement(0.001) ) << "\n";

    // Close file
    outf.close();
}

/*!
 * Record voltage from a current ramp
 */
void KeithleyWindow::ivCurveMeasurement()
{
    // Open the file
    QFile outf{beamOffFilename_ + QString{ui->spnDatumNum_->value()} };
    if (!outf.open(QIODevice::Append))
    {
        QMessageBox msg;
        msg.setText("Could not open iv curve file");
        return;
    }

    // Create a text stream to write out everything
    QTextStream outstr(&outf);

    // Store the time
    outstr << QTime::currentTime().toString("hh:mm:ss") << ", ";

    // Write out Fluence and Measurement for a ramp of current
    double amp{0};
    for (int i = 0; i < 210; i++)
    {
        amp = 1e-9*pow(10, i/30.0);
        outstr << ui->spnFluence_->value() << "e" << ui->spnFluenceExp_->value() <<
                  ", " << QString::fromStdString( kdev_.forward_voltage_measurement(amp) ) << "\n";
    }

    // Close file
    outf.close();
}
