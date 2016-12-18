#ifndef ESAGGREGATION_H
#define ESAGGREGATION_H

#include <QVariant>
#include <QVariantMap>

class ESAggregation : public QVariantMap
{
public:

ESAggregation()
{

}

    //        Aggregations
//                Min Aggregation
    static ESAggregation min(QString field, QString script = "", QVariantMap params = NULL)
    {
        QVariantMap aggParams;
        aggParams["field"] = field;
        if(script)
        {
            aggParams["script"] = script;
            if(params)
                aggParams["params"] = params;
        }
        this["min"] = aggParams;
    }

//                Max Aggregation
    static ESAggregation max(QString field, QString script = "", QVariantMap params = NULL);
//                Sum Aggregation
    static ESAggregation sum(QString field, QString script = "", QVariantMap params = NULL);
//                Avg Aggregation
    static ESAggregation avg(QString field, QString script = "", QVariantMap params = NULL);
//                Stats Aggregation
    static ESAggregation stats(QString field, QString script = "", QVariantMap params = NULL);
//                Extended Stats Aggregation
    static ESAggregation statsExtended(QString field, QString script = "", QVariantMap params = NULL);
//                Value Count Aggregation
    static ESAggregation count(QString field, QString script = "", QVariantMap params = NULL);
//                Percentiles Aggregation
    static ESAggregation percentiles(QString field, QString script = "", QVariantMap params = NULL, QList<float> percents = NULL, int compression = 100);
//                Percentile Ranks Aggregation
//                Cardinality Aggregation
//                Geo Bounds Aggregation
//                Top hits Aggregation
//                Scripted Metric Aggregation
//                Global Aggregation
//
//                Missing Aggregation

//
//                Terms Aggregation
//                Significant Terms Aggregation
//                Range Aggregation
//                Date Range Aggregation
//                IPv4 Range Aggregation
//                Histogram Aggregation
//                Date Histogram Aggregation
//                Geo Distance Aggregation
//                GeoHash grid Aggregation

//                Filter Aggregation
//                Filters Aggregation

//                Nested Aggregation
//                Reverse nested Aggregation
//                Children Aggregation
    void addSubAgg(QString name, ESAggregation agg)
    {
        if(!this->contains("aggregations"))
            this["aggregations"] = new QMap<QString, ESAggregation>();
        this["aggregations"][name] = agg;
    }

private:
    ESAggregation();
    //QVariantMap _self;
    //_self["<agg_type>"] = QVariantMap options;
    //_self["aggregations"] = QMap<String, ESAggregation>
};

#endif // ESAGGREGATION_H
