GXX=g++
LDLIBS=-lIrrlicht -lstdc++
OBJECTS=Main.o Map.o Racer.o HumanRacer.o CPURacer.o
CFLAGS=-Wall

race: $(OBJECTS)
	$(GXX) $(OBJECTS) $(LDLIBS) -o race

Main.cpp: Main.hpp Map.cpp Racer.cpp HumanRacer.cpp

Map.cpp: Map.hpp

Racer.cpp: Racer.hpp

HumanRacer.cpp: HumanRacer.hpp Racer.hpp

CPURacer.cpp: CPURacer.hpp Racer.hpp

.PHONY: clean
clean:
	rm -rf $(OBJECTS) race

.PHONY: run
run:
	./race
