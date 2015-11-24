#include "keithleywindow.h"
#include "ui_keithleywindow.h"
#include <QFileDialog>

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
