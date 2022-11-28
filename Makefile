CPP=g++
CPPFLAGS=-Wall -O2 -fpermissive
LFLAGS=-lm
CPP_OBJECTS=main.o memory.o util.o


all: clean run

clean:
	rm -f *.o mmod

%.o: %.cpp
	$(CPP) $(CPPFLAGS) $^ -c -o $@

mmod: $(CPP_OBJECTS)
	$(CPP) $(CPP_OBJECTS) -o $@ $(LFLAGS)

target:
	gcc target.c -o target

run: mmod target
	./target > /dev/null & ./mmod $$(pidof target)
	killall target
