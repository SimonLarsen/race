GXX=g++
LDLIBS=-lIrrlicht -lstdc++
OBJECTS=Main.o Map.o Racer.o HumanRacer.o

race: $(OBJECTS)
	$(GXX) $(OBJECTS) $(LDLIBS) -o race

Main.cpp: Main.hpp Map.hpp

Map.cpp: Map.hpp

Racer.cpp: Racer.hpp

HumanRacer.cpp: HumanRacer.hpp Racer.hpp

.PHONY: clean
clean:
	rm -rf *.o race

.PHONY: run
run:
	./race
