#ifndef ELASTICSEARCH_H
#define ELASTICSEARCH_H

#include <QObject>
#include "restrequest.h"

class ElasticSearch : public QObject
{
    Q_OBJECT
public:
    explicit ElasticSearch(QObject *parent = 0) : QObject(parent)
    {
        this->index = "stream";
        this->type = "node";
    }

 QString index;
 QString type;

    //    Document APIs
        //    Index API
        
        // Call to index doc
        // This class emits an error signal if something goes wrong
        // Call the checkStatus() method to see if it succeeded
        QVariantMap addDoc(QVariantMap doc)
        {
            RestRequest::doPost("localhost:9200/" + this->index + "/" + this->type,
                                doc,
                                SLOT(addDone(QVariantMap)),
                                this);

            this->addStatus[doc["id"]] = ADD_SENT;
        }
        void addDone(QVariantMap response)
        {
            if(respose["error"] = ...)
                emit addError("We got a problem");
            else
                this->addStatus[respose["docid"]] = ADD_SUCCESS;
        }




        QVariantMap updateDoc(QVariantMap doc, QString id, int version);
        //    Get API
        QVariantMap getDoc(QString id, const char * docSlot)
        {

        }
        //    Delete API
        QVariantMap deleteDoc(QString id);
        //    Update API
        QVariantMap scriptUpdateDoc(QString id, QString script, QVariantMap params);
        //    Multi Get API
        QVariantList getMultipleDocs(QStringList ids);
        //    Bulk API
        QVariantList bulk(QList<QString, QVariantMap> actions);
        //    Term Vectors
        QVariantMap getTermVector(QString id, QStringList fields); // Parameters? Default to all?
        //    Multi termvectors API
        QVariantList getTermVectors(QStringList ids, QStringList fields); // Parameters? Default to all?

    //    Search APIs
    //        Search
        QVariantList search(ESQuery query, QString scroll = "");
    //        Search Template
        QVariantMap searchByTemplate(ESQuery query_template, QVariantMap params);
    //        Search Shards API
    //        Suggesters
        QVariantMap suggest(QVariantMap in);
    //        Multi Search API
        QVariantList multiSearch(QList<ESQuery> qs);
    //        Count API
        int count(ESQuery q);
    //        Search Exists API
        bool anyExist(ESQuery q);
    //        Validate API (validates queries - useful?)
    //        Explain API
        QVariantMap explain(QString docId, ESQuery q);
    //        Percolator
        QVariantMap registerReverseQuery(ESQuery q);
        QVariantMap reverseQuery(QVariantMap doc);
        QVariantMap reverseQuery(QString docId);
    //        More Like This API (DEPRECATED in favor of MLT query)
    //        Field stats API (EXPERIMENTAL)
        QVariantMap fieldStats(QStringList fields);

    //    Indices APIs
    //        Index management
    //            Create Index
    //            Delete Index
    //            Get Index
    //            Indices Exists
    //            Open / Close Index API
    //        Mapping management
    //            Put Mapping
    //            Get Mapping
           QVariantMap getMapping();
    //            Get Field Mapping
    //            Delete Mapping
    //            Types Exists
    //        Alias management
    //            Index Aliases
    //        Index settings
    //            Update Indices Settings
    //            Get Settings
    //            Analyze
           QVariant analyze(QString text);
    //            Index Templates - go in templates dir
    //            Warmers
           QVariantMap registerWarmer(ESQuery q);
    //        Replica configurations
    //            Shadow replica indices
    //        Monitoring
    //            Status (DEPRECATED in favor of indices recovery api)
    //            Indices Stats
           QVariantMap stats();
    //            Indices Segments
    //            Indices Recovery
    //        Status management
    //            Clear Cache
           QVariantMap clearCache();
    //            Refresh
    //            Flush
           QVariantMap flush();
    //            Optimize
           QVariantMap optimize();
    //            Upgrade
           QVariantMap upgrade(); // This shouldn't really be needed

    //    Cluster APIs
    //        Cluster Health
           QVariantMap clusterHealth();
    //        Cluster State
           QVariantMap clusterState();
    //        Cluster Stats
           QVariantMap clusterStats();
    //        Pending cluster tasks
    //        Cluster Reroute
    //        Cluster Update Settings
    //        Nodes Stats
    //        Nodes Info
    //        Nodes hot_threads
    //        Nodes Shutdown

    //    Mapping
    //        Fields
    //        Types
    //        Date Format
    //        Dynamic Mapping
    //        Config Mappings
    //        Meta
    //        TransformFields
    //        Types
    //        Date Format
    //        Dynamic Mapping
    //        Config Mappings
    //        Meta
    //        Transform

    //    Analysis
    //        Analyzers
    //        Tokenizers
    //        Token Filters
    //        Character Filters
    //        ICU Analysis Plugin

    //    Modules
    //    Index Modules

signals:

public slots:
           void addDone(QVariantMap response);

private:
           QVariantMap addStatus;

};

#endif // ELASTICSEARCH_H

