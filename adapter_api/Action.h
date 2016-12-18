 class Action
   {
   public:
     std::map<std::string, Schema> inputs;
     std::map<std::string, Schema> outputs;
     Verb verb;
     Adapter provider;
     Command instantiate();
   };