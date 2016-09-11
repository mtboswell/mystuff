#ifndef NODE_H
#define NODE_H

#include <QObject>
#include <QUrl>
#include <QDateTime>
#include <QLocale>
#include <QGeoCoordinate>
#include <QThread>
#include <QHostInfo>
#include "elasticsearch.h"

class NodeInputAdapter : public QThread
{
    Q_OBJECT
    public:
        explicit NodeInputAdapter(QObject *parent = 0) : QThread(parent){}

    signals:
        void newNode(QMap<QString, QVariant>);

        public slots:

    protected:
        void setDefaultMeta(QMap<QString, QVariant> * node)
        {
            (*node)["_node_added_timestamp"] = QDateTime::currentDateTime();
#ifdef _win32
            (*node)["_node_source_user"] = QProcessEnvironment::systemEnvironment().value("USERNAME");
#else
            (*node)["_node_source_user"] = QProcessEnvironment::systemEnvironment().value("USER");
#endif
            (*node)["_node_source_host"] = QHostInfo::localHostName();
        }
        void mainInputLoop(){}
        void commitNode(QMap<QString, QVariant> * node);
};

#endif // NODE_H
