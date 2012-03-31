GXX=g++
LDLIBS=-lIrrlicht -lstdc++
OBJECTS=Main.o

race: $(OBJECTS)
	$(GXX) $(OBJECTS) $(LDLIBS) -o race

Main.o: Main.cpp Main.hpp
	$(GXX) -c Main.cpp

.PHONY: clean
clean:
	rm -rf *.o race

.PHONY: run
run:
	./race
