#include <QCoreApplication>

struct engine
{
#include "fileadapter.cpp"
#include "mailadapter.cpp"

    //#include "hub.h"
    //static Hub _g;
    
    static int Main(QCoreApplication app)
    {
        FileAdapter fa();
        MailAdapter ma();

        fa.start();
        ma.start();

        return app.exec();
    }
};

//engine::Hub engine::_g;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return engine::Main(a);
}
