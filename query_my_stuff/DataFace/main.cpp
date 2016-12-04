#include "datafacemainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataFaceMainWindow w;
    w.show();

    return a.exec();
}
