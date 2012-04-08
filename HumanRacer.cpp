#include "HumanRacer.hpp"

HumanRacer::HumanRacer() { }

void HumanRacer::updateInput(bool* keystates, f32 dt) {
	acc = turn = 0.f;

	if(keystates[KEY_SPACE]) {
		acc = 1.f;
	}

	if(keystates[KEY_KEY_A]) {
		turn = 1.f;
	} else if(keystates[KEY_KEY_D]) {
		turn = -1.f;
	}
}
