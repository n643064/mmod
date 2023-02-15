CPP=g++
CPPFLAGS=-Wall -O2 -fpermissive -std=c++17
LFLAGS=-lm
CPP_OBJECTS=main.o map.o memory.o util.o


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

test-target: clean target
	./target & killall target

run: mmod target
	./target & ./mmod $$(pidof target)
