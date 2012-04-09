#ifndef __RACER_HPP
#define __RACER_HPP

#include <irrlicht/irrlicht.h>
using namespace irr;
#include <irrlicht/irrMath.h>
#include <iostream>

#define FRICTION 0.3

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
	f32 speed, xforce, zforce, dir;
	f32 i_acc, i_turn; // Input parameters, set by subclasses

	//stats
	f32 S_TURNSPEED, S_ACCELERATION, S_TOPSPEED;
};

#endif
