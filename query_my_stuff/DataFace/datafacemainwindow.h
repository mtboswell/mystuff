#ifndef DATAFACEMAINWINDOW_H
#define DATAFACEMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class DataFaceMainWindow;
}

class DataFaceMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataFaceMainWindow(QWidget *parent = 0);
    ~DataFaceMainWindow();

private:
    Ui::DataFaceMainWindow *ui;
};

#endif // DATAFACEMAINWINDOW_H
