#include "datafacemainwindow.h"
#include "ui_datafacemainwindow.h"

DataFaceMainWindow::DataFaceMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataFaceMainWindow)
{
    ui->setupUi(this);
}

DataFaceMainWindow::~DataFaceMainWindow()
{
    delete ui;
}
