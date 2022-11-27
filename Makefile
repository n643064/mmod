CPP=g++
CPPFLAGS=-Wall -O2 -fpermissive
LFLAGS=-lm
CPP_OBJECTS=main.o memory.o

ARGV=

all: clean run

clean:
	rm -f *.o mmod

%.o: %.cpp
	$(CPP) $(CPPFLAGS) $^ -c -o $@

mmod: $(CPP_OBJECTS)
	$(CPP) $(CPP_OBJECTS) -o $@ $(LFLAGS)

run: mmod
	./mmod $(ARGV)
