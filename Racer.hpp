#ifndef __RACER_HPP
#define __RACER_HPP

#include <irrlicht/irrlicht.h>
using namespace irr;

class Racer {
public:
	scene::ISceneNode* create(IrrlichtDevice* device, f32 x, f32 z, f32 dir);
	void update(f32 dt);
	virtual void handleInput();

protected:
	bool isSolid;
	scene::ISceneNode* node;
	f32 x, y, z, xspeed, zspeed, dir;
};

#endif
