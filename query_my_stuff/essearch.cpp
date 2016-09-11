#ifndef ESSEARCH_H
#define ESSEARCH_H


class ESSearch
{
public:
    ESSearch();

    enum ESSearchType {QUERY_THEN_FETCH, DFS_QUERY_THEN_FETCH,
                      COUNT, SCAN, QUERY_AND_FETCH, DFS_QUERY_AND_FETCH};

//                Query (see later)
//                From / Size
    ESSearch * from(int frm = 0){_req["from"] = frm;return this;}
    ESSearch * size(int cnt = 10){_req["size"] = cnt;return this;}
//                Sort (true = descending)
    ESSearch * sort(QList<QPair<QString, bool> > fields );
//                Source filtering
    ESSearch * filterReturnedSource(bool returnSource);
    ESSearch * filterReturnedSource(QStringList include);
    ESSearch * filterReturnedSource(QStringList include, QStringList exclude);
//                Fields
    ESSearch * filterReturnedFields(QStringList fields);
//                Script Fields
                    // Field name, script, params
    ESSearch * addCalculatedFields(QMap<QString, QPair<QString, QVariantMap> > cFields);
//                Field Data Fields
    ESSearch * getFieldData(QStringList fields);
//                Post filter (Applies result filters after calculating aggregations)
    ESSearch * filterResultsOnly(ESFilter filter);
//                Highlighting
    ESSearch * highlight(QStringList fields, QStringList pre_tags = NULL, QStringList post_tags = NULL, ESSearch query = NULL);
//                Rescoring
    ESSearch * rescore(ESSearch rescoreQuery, int windowSize, float rescorePrecedence);
//                Search Type
    ESSearch * searchType(ESSearchType type);
//                Scroll (in URL)
    ESSearch * scroll(QString time);
//                Preference (replica preference)
    ESSearch * preferReplica(QString replica = "_local");
//                Explain
    ESSearch * returnExplanations();
//                Version
    ESSearch * returnVersions();
//                Index Boost
    ESSearch * boostByIndex(QMap<QString, Float>);
//                min_score
    ESSearch * minScore(float score){_req["min_score"]=score;return this;}
signals:

public slots:
private:
        QVariantMap _req;
        QVariantMap _get;
};

#endif // ESSEARCH_H
