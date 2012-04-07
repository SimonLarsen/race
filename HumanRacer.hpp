#ifndef __HUMANRACER_HPP
#define __HUMANRACER_HPP

#include "Racer.hpp"

class HumanRacer : public Racer {
public:
	HumanRacer();
	void handleInput();
};

#endif
