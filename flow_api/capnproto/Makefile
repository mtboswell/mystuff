
objdir := bin
objects := $(addprefix $(objdir)/, $(patsubst %.capnp,%.o,$(wildcard *.capnp)))

default: $(objects)

generated/%.capnp.c++: %.capnp
	mkdir -p generated
	capnp compile -oc++ $<
	mv *.capnp.* generated/

bin/%.o: generated/%.capnp.c++
	mkdir -p bin
	g++ -shared -fPIC -std=c++11 -o $@ $< -Igenerated -lcapnp -lkj

clean: 
	rm -r bin/ generated/
