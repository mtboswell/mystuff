#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->availableBackendsMenu = new QMenu(ui->addBackendButton);
    foreach(QAction act, getBackendCreateActions())
    {
        this->availableBackendsMenu.add(act);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addBackendButton_clicked()
{
    this->avaiableBackendsMenu.show();
}
