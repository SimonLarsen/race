#ifndef __RACER_HPP
#define __RACER_HPP

#include <irrlicht/irrlicht.h>
using namespace irr;
#include <irrlicht/irrMath.h>
#include <iostream>

// TODO: Get from terrain in case of ice or something
#define FRICTION 0.06f

class Racer {
public:
	scene::ISceneNode* create(IrrlichtDevice* device, f32 x, f32 z, f32 dir);
	void updateLogic(f32 dt);
	void update(bool* keystates, f32 dt);
	void setCameraBehind(scene::ICameraSceneNode* camera);
	virtual void updateInput(bool* keystates, f32 dt);

protected:
	bool isSolid;
	scene::ISceneNode* node;
	core::vector3df pos;
	f32 speed, dir, turndir;
	f32 i_acc, i_turn; // Input parameters, set by subclasses

	//stats
	f32 S_TURNSPEED, S_ACCELERATION, S_TOPSPEED, S_MAXTURN;
};

#endif
