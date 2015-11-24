#ifndef KEITHLEYWINDOW_H
#define KEITHLEYWINDOW_H

#include <QMainWindow>
#include <memory>
#include <QString>

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

    //! Beam On filename
    QString beamOnFilename_;

    //! Record a measurement to the given file
    void genericBeamMeasurement( const QString &fname );

private slots:
    //! select a new beam off file
    void newBeamOffFile();

    //! select a new beam on file
    void newBeamOnFile();

    //! Record timestamp, Fluence and voltage measurement to beam off file
    void beamOffMeasurement();

    //! Record timestamp, Fluence and voltage measurement to beam on file
    void beamOnMeasurement();

    //! Record voltage from a current ramp
    void ivCurveMeasurement();
};

#endif // KEITHLEYWINDOW_H
