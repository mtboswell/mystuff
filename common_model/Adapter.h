
class Adapter
{
  public:
      Adapter();
      ~Adapter();
      Action[] listActionTuples();
      Schema getSchema();
      void execute(Command, void * callback(CommandStatus));
      void authenticate();
      DocSet get(Query);
};