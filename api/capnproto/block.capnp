enum LibType {
  Native @0;
  Java @1;
  Python @2;
  Perl @3;
  Bash @4;
}

struct Library {
  name @2 : Text;
  source @0 : Text;
  type @1 : LibType;
  version @3 : Text;
  category @4 : Text;
  
}

struct Type {
  name @0 : Text;
  namespace : Text;
  lib @2 : Library;
  include : Text;
  templateParams : List(Text);
  documentation : Text;
 }

struct Parameter {
  name @0: Text;
  union type {
    class @1 : Type;
    templateParam : uint8;
  }
  direction : ParamDir;
  ref : Bool = false;
  ptrLevel : uint8 = 0;
  arrayLevel : uint8 = 0;
  documentation : Text;
}

struct Method {
  union type {
    none @0 : void;
    class @1 : Type;
	}
  name @3 : Text;
  parameters @4 : List(Parameter);
  return @5 : Parameter;
  static @6 : Bool = false;
  include : Text;
  documentation : Text;
  category : Text;
  lib : Library;
}

struct Multiplicity {
  min : int32 = 0;
  max : int32 = -1;
}

enum ArgType {
  freetext;
  nested;
  array;
  flag;
  filename;
  list;
  
}

struct ArgOption {
  union {
    text : Text;
    arg : AppArgument;
  }
}

struct AppArgument {
  descriptipn : Text;
  prefix : Text = "--";
  postfix : Text = "";
  type : ArgType;
  options : List(ArgOption);
  optionMultiplicity : Multiplicity;
  delimiter : Text = " ";
}

enum StreamType {
  file
socket
pipe
local
}

struct StreamFormat {
  name : Text;
}

struct Stream {
  type : StreamType;
  format : StreamFormat;
  readable : Bool;
  writable : Bool;
  seekable : Bool;
  location : Text;
}

struct Application {
  name : Text;
  source : Text;
  args : List(AppArgument);
  stdin : AppStream;
  stdout : AppStream;
  stdinEnableArg : Text;
  stdoutDisableArg 
  stdoutRedirectArg
  
}

struct Block {
  union {
    method : Method;
    app : Application;
  }
}
