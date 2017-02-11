@0xad1661d25ae6f2d4;

enum LibType {
  native @0;
  java @1;
  python @2;
  perl @3;
  bash @4;
}

struct Library {
  name @0 :Text;
  source @1 :Text;
  type @2 :LibType;
  version @3 :Text;
  category @4 :Text;
  
}

struct Type {
  # Language data type, e.g. std::String
  name @0 :Text;
  namespace @1 :Text;
  lib @2 :Library;
  include @3 :Text;
  templateParams @4 :List(Text);
  documentation @5 :Text;
}

enum ParamDirection {
  in @0;
  out @1;
  inout @2;
}

struct Parameter {
  name @0: Text;
  type :union {
    class @1 :Type;
    templateParam @2 :UInt8;
  }
  direction @3 :ParamDirection;
  ref @4 :Bool = false;
  ptrLevel @5 :UInt8 = 0;
  arrayLevel @6 :UInt8 = 0;
  documentation @7 :Text;
}

struct Method {
  type :union {
    none @0 :Void;
    class @1 :Type;
  }
  name @2 :Text;
  parameters @3 :List(Parameter);
  return @4 :Parameter;
  static @5 :Bool = false;
  include @6 :Text;
  documentation @7 :Text;
  category @8 :Text;
  lib @9 :Library;
}

struct Multiplicity {
  min @0 :Int32 = 0;
  max @1 :Int32 = -1;
}

enum ArgType {
  freetext @0;
  nested @1;
  array @2;
  flag @3;
  filename @4;
  list @5;
}

struct ArgOption {
  union {
    text @0 :Text;
    arg @1 :AppArgument;
  }
}

struct AppArgument {
  descriptipn @0 :Text;
  prefix @1 :Text = "--";
  postfix @2 :Text = "";
  type @3 :ArgType;
  options @4 :List(ArgOption);
  optionMultiplicity @5 :Multiplicity;
  delimiter @6 :Text = " ";
}

enum StreamType {
  file @0;
  socket @1;
  pipe @2; 
  local @3;
}

struct StreamFormat {
  name @0 :Text;
}

struct Stream {
  type @0 :StreamType;
  format @1 :StreamFormat;
  readable @2 :Bool;
  writable @3 :Bool;
  seekable @4 :Bool;
  location @5 :Text;
}

struct AppStream {
}

struct Application {
  name @0 :Text;
  source @1 :Text;
  args @2 :List(AppArgument);
  stdin @3 :AppStream;
  stdout @4 :AppStream;
  stdinEnableArg @5 :Text;
  stdoutDisableArg @6 :Text;
  stdoutRedirectArg @7 :Text;
}

struct Block {
  union {
    method @0 :Method;
    app @1 :Application;
  }
}
