#ifndef __HUMANRACER_HPP
#define __HUMANRACER_HPP

#include <irrlicht/irrlicht.h>
using namespace irr;
#include "Racer.hpp"

class HumanRacer : public Racer {
public:
	HumanRacer();
	void updateInput(bool* keystate, f32 dt);
};

#endif
