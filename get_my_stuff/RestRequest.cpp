#ifndef RESTREQUEST_H
#define RESTREQUEST_H

#include <QtNetwork>

class RestRequest : public QObject
{
    Q_OBJECT
        public slots:
    static void doPost(QString urlString, QVariant data, const char *responseCallback, QObject * parent)
    {
        RestRequest * req = new RestRequest(parent);
        QJsonDocument jsonDoc = QJsonDocument::fromVariant(&data);
        connect(req, SIGNAL(done(QVariantMap)), parent, responseCallback);
        req->request = new QNetworkRequest( QUrl( urlString ) );
        req->multiPart = new QHttpMultiPart();
        req->multiPart.setContentType();
        req->multiPart.setUserData(0, jsonDoc.toJson(QJsonDocument::JsonFormat::Compact));
        request.setRawHeader("Authorization", "Basic " +
                QByteArray(QString("%1:%2").arg("user").arg("asas").toAscii()).toBase64());
        request.setHeader(QNetworkRequest::ContentTypeHeader, "text/xml");

        req->netManager.post(request, &multiPart);
    }

private:
    RestRequest(QObject *parent = 0) : QObject(parent)
    {
        QObject::connect(&netManager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(parseNetworkResponse(QNetworkReply*)));
    }
    QNetworkAccessManager netManager;
    QNetworkRequest * request;
    QHttpMultiPart * multiPart;

signals:
    void done(QVariantMap);

private slots:
    void networkError( QNetworkReply::NetworkError err );
    void parseNetworkResponse( QNetworkReply *finished )
    {
        delete(this->request);
        delete(this->multiPart);
        if ( finished->error() != QNetworkReply::NoError )
        {
            // A communication error has occurred
            emit networkError( finished->error() );
            this->deleteLater();
            return;
        }

        // QNetworkReply is a QIODevice. So we read from it just like it was a file
        QByteArray data = finished->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromBinaryData(&data);
        QVariantMap response = jsonDoc.toVariant();

        this->deleteLater();
        emit done( response );
    }
};

#endif // RESTREQUEST_H
