 class Field
   {
   public:
   Field();
   std::string name;
   FieldType type;
   Field[] meta;
   };

class Schema : public Field
  {
  public:
  Schema();
  Field[] fields;
  };