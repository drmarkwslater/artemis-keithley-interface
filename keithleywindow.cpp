#include "keithleywindow.h"
#include "ui_keithleywindow.h"

KeithleyWindow::KeithleyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KeithleyWindow)
{
    ui->setupUi(this);
}

KeithleyWindow::~KeithleyWindow()
{
    delete ui;
}
