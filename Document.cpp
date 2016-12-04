
class Document : public QObject
{
    public:
        Document(QTree<QVariant, QVariant> init);
        ~Document();
        get(QString field);
        set(QString field, QVariant value);
        query(QString field, QString path); // Like xpath on structured fields

    private:

};
