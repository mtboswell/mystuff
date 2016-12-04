
enum GenericTypes {
    IMAGE_RASTER,
    VIDEO_RASTER,
    MESSAGE,
    REQUEST_FOR_DATA,
    COMMAND,
    VECTOR_GEOMETRY,
};

enum Dimensions {
    X,
    Y,
    Z,
    T,
    R,
    G,
    B,
    A,
    C,
    M,
    Y,
    K,


    SPATIAL,
    COLOR,
    TEMPERATURE,
    TIME,
    WORDS,
};


/ USE MIME
class DataType
{
    public:
        DataType();
        ~DataType();

        QString name;
        type storageType;
        GenericTypes genericType;
        Validator validator;
        int dimensions;
        QString[] units;
        bool si;

};
