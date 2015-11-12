#ifndef KEITHLEYWINDOW_H
#define KEITHLEYWINDOW_H

#include <QMainWindow>

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
    Ui::KeithleyWindow *ui;
};

#endif // KEITHLEYWINDOW_H
