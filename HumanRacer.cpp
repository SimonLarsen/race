#include "HumanRacer.hpp"

HumanRacer::HumanRacer() { }

void HumanRacer::updateInput(bool* keystates, f32 dt) {
	i_acc = i_turn = 0.f;

	if(keystates[KEY_UP]) {
		i_acc = 1.f;
	} else if(keystates[KEY_DOWN]) {
		i_acc = -1.f;
	}

	if(keystates[KEY_LEFT]) {
		i_turn = 1.f;
	} else if(keystates[KEY_RIGHT]) {
		i_turn = -1.f;
	}
}
