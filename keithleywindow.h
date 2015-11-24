#ifndef KEITHLEYWINDOW_H
#define KEITHLEYWINDOW_H

#include <QMainWindow>
#include <memory>
#include "keithleydevice.h"

namespace Ui {
class KeithleyWindow;
}

class KeithleyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit KeithleyWindow(QWidget *parent = 0);
    ~KeithleyWindow();

private:
    //! Pointer to UI
    Ui::KeithleyWindow *ui;

    //! Keithley Device object
    KeithleyDevice kdev_;

    //! Beam Off filename
    QString beamOffFilename_;

private slots:
    //! select a new beam off file
    void newBeamOffFile();
};

#endif // KEITHLEYWINDOW_H
