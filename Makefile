GXX=g++
LDLIBS=-lIrrlicht -lstdc++
OBJECTS=Main.o Map.o Racer.o HumanRacer.o

race: $(OBJECTS)
	$(GXX) $(OBJECTS) $(LDLIBS) -o race

Main.o: Main.cpp Main.hpp Map.hpp
	$(GXX) -c Main.cpp

Map.o: Map.cpp Map.hpp
	$(GXX) -c Map.cpp

Racer.o: Racer.hpp Racer.cpp
	$(GXX) -c Racer.cpp

HumanRacer.o: HumanRacer.hpp HumanRacer.cpp Racer.hpp
	$(GXX) -c HumanRacer.cpp

.PHONY: clean
clean:
	rm -rf *.o race

.PHONY: run
run:
	./race
