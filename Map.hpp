#ifndef __MAP_HPP
#define __MAP_HPP

#include <irrlicht/irrlicht.h>
#include <irrlicht/irrString.h>
using namespace irr;

class Map {
public:
	bool load(core::stringc name);
	void createScene(IrrlichtDevice* device);

	enum E_DECORATION_TYPE {
		EDT_PURPLE_ROCK, EDT_TENTACLE
	};

	core::stringc plane_textures[4];
	core::stringc skybox_textures[5]; // bottom, left, right, front, back
	int startpositions[8][2];
private:
	scene::IBillboardSceneNode* addDecorationBillboard(IrrlichtDevice* device, f32 x, f32 z, E_DECORATION_TYPE type);
};

#endif
