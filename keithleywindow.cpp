#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

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
 * Record a measurement
 */
void KeithleyWindow::beamOffMeasurement()
{
    // Open the file
    QFile outf{beamOffFilename_};
    if (!outf.open(QIODevice::Append))
    {
        QMessageBox msg;
        msg.setText("Could not open BEAM OFF file");
        return;
    }

    // Write out appropriate things
    QTextStream outstr(&outf);
    outstr << "Hello" << "\n";
}
