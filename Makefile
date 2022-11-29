CPP=g++
CPPFLAGS=-Wall -O2 -fpermissive
LFLAGS=-lm
CPP_OBJECTS=main.o memory.o util.o


all: clean run

clean: build
	rm -f build/* mmod target

build:
	mkdir build

%.o: src/%.cpp
	$(CPP) $(CPPFLAGS) $^ -c -o build/$@


mmod: $(CPP_OBJECTS)
	cd build && $(CPP) $(CPP_OBJECTS) -o ../$@ $(LFLAGS)
	
target:
	gcc src/target.c -o target

run: mmod target
	./target > /dev/null & ./mmod $$(pidof target)
	killall target
