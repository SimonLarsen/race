#ifndef __MAP_HPP
#define __MAP_HPP

#include <irrlicht/irrlicht.h>
#include <irrlicht/irrString.h>
using namespace irr;

class Map {
public:
	bool load(core::stringc name);
	void createScene(IrrlichtDevice* device);

	core::stringc plane_textures[4];
	core::stringc skybox_textures[6];
	int startpositions[8][2];
};

#endif
