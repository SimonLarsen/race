#include "Racer.hpp"

scene::ISceneNode* Racer::create(IrrlichtDevice* device, f32 _x, f32 _z, f32 _dir) {
	x = _x;
	y = 0.f;
	z = _z;
	dir = _dir;
	isSolid = true;

	scene::ISceneManager* smgr = device->getSceneManager();
	node = smgr->addBillboardSceneNode(0, core::dimension2df(32.f,32.f), core::vector3df(x,16.f,z));
	return node;
}

void Racer::handleInput() {

}

void Racer::update(f32 dt) {
}
