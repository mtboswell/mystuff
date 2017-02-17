@0xd2a9e4187009fdc2;

using Block = import "block.capnp";

struct BlockRef {
  blockId @0 :Text;
  scrLoc @1 :List(UInt16); # Location of block in edit space
}

struct PortRef {
  block @0 :BlockRef;
  type @1 :Block.TypeRef;
  portDir @1 :Block.IoDirection;
  portIndex @2 :Text;
}

# Want to be able to link types that are compatible, e.g. std::List<String> to std::Iterable<Object>. I suppose we need a polymorph tree or at least inheritance/interfaceimpl info.

struct Link
{
  portA @0 :PortRef;
  portB @1 :PortRef;
}
