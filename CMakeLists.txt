project(race)
cmake_minimum_required(VERSION 2.8)
link_libraries(Irrlicht stdc++)
add_executable(race CPURacer.cpp CPURacer.hpp HumanRacer.cpp HumanRacer.hpp Main.cpp Main.hpp Map.cpp Map.hpp Racer.cpp Racer.hpp)
