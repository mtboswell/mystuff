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
  # Class/data type, e.g. std::String
  name @0 :Text;
  namespace @1 :Text;
  lib @2 :Library;
  include @3 :Text;
  templateParams @4 :List(Text); # implies isGeneric
  documentation @5 :Text;
  inherits @6 :List(TypeRef);
  isContainer @7 :Bool; 
  containedType @8 :Text; # Reference to either a type or a templateParam
  isVirtual @9 :Bool;
  isStatic @10 :Bool;
  fields @11 :List(FieldDef);
  operations @12 :List(Method);
}
# When a link is made between ports with different types, a converter block is added, either from an existing lib or a new custom block. Also for containers, e.g. std::vector<String> output linked to QString input results in iteration or map/reduce or something with each element converted with the std::String to QString conversion.

struct TypeRef {
  type :union {
    void @0 :Void;
    raw @1 :Type; # Non-generic type
    instance @2 :TypeInstance; # Generic type
    templateParam :union { # Type from this generic class's template args. When accessed throuogh a TypeInstance this should be replaced with the instance's actual parameter type.
      index @3 :UInt8; # For faster lookups
      name @4 :Text; # Requires finding the index of the template param name then finding that index in the TypeInstances params
    }
  }

  struct TypeInstance { # Instance of a generic type. If type's templateParam list is empty, this is an invalid TypeRef.
    type @0 :TypeRef;
    templateTypes @1 :List(TypeRef); # Also serves as param type list for function pointers
  }

  ptrLevel @5 :UInt8 = 0; # Could be bool, then ptr to ptr would be nested
  arrayLevel @6 :UInt8 = 0; # How many dimensions of array
  arraySize @7 :List(UInt64); # Array dimensions
}


enum IoDirection {
  in @0;
  out @1;
  inout @2;
}

struct ParameterPort {
  name @0: Text;
  type: @1 :TypeRef;
  direction @3 :IoDirection;
  ref @4 :Bool = false;
  documentation @7 :Text;
}

struct Method {
  name @0 :Text;
  class @1 :Type; # Optional
  parameters @2 :List(ParameterPort);
  return @3 :ParameterPort;
  static @4 :Bool = false; # If the method is not static we'll need an instance of the type as an input port
  include @5 :Text;
  documentation @6 :Text;
  category @7 :Text;
  lib @8 :Library;
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

enum StreamFormat {
  # StreamFormat is used to determine what sort of adapter to use for links
  id @0 :Text;
  # examples
  #text-line-delimited 
  #text-null-delimited
  #binary-protobuf
  #binary-capnproto
  #binary-data
}

enum TextEncoding {
  ascii @0;
  utf8 @1;
  latin @2;
  other @3;
}

struct Stream {
  type @0 :StreamType;
  format @1 :StreamFormat;
  formatStructure @2 :Text;
  readable @3 :Bool;
  writable @4 :Bool;
  seekable @5 :Bool;
  location @6 :Text;
}

struct AppStream {
  # What's the difference from Stream?
}

enum AppSourceType {
  apt @0;
  yum @1;
  gem @2;
  pip @3;
  npm @4;
  pacman @5;
  aur @6;
  maven @7;
}

struct AppSource {
  url @0 :Text;
  type @1 :AppSourceType;
  repoVersion @2 :Text;
}

struct Application {
  name @0 :Text; # Should be able to exec `which $name`
  source @1 :AppSource;
  args @2 :List(AppArgument);
  stdin @3 :AppStream; # Describes data type and format expected on stdin
  stdout @4 :AppStream; # Describes data type and format produced on stdout
  stderr @5 :AppStream;
  stdinEnableArg @6 :AppArgument; # Argument that activates reading from stdin, if any
  stdoutDisableArg @7 :AppArgument; # Argument that shuts up stdout (e.g. -q)
  stdoutRedirectArg @8 :AppArgument; # Argument that redirects stdout (e.g. -o)
  stdinDelimiterArg @9 :AppArgument; # Argument that controls the input delimiter (e.g. cut's -f or xarg's -0)

}

struct Block {
  # A block is a function in the functional programming paradigm
  # Blocks can be run locally, accessed via RPC, or executed remotely
  union {
    method @0 :Method;
    app @1 :Application;
  }
}
