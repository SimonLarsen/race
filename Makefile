GXX=g++
LDLIBS=-lIrrlicht -lstdc++
OBJECTS=Main.o Map.o

race: $(OBJECTS)
	$(GXX) $(OBJECTS) $(LDLIBS) -o race

Main.o: Main.cpp Main.hpp Map.hpp
	$(GXX) -c Main.cpp

Map.o: Map.cpp Map.hpp
	$(GXX) -c Map.cpp

.PHONY: clean
clean:
	rm -rf *.o race

.PHONY: run
run:
	./race
