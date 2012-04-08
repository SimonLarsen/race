#include "Racer.hpp"

scene::ISceneNode* Racer::create(IrrlichtDevice* device, f32 _x, f32 _z, f32 _dir) {
	pos.X = _x;
	pos.Y = 8.f;
	pos.Z = _z;
	dir = _dir;
	turn = speed = 0.f;
	isSolid = true;

	// TODO: Read these from different characters
	S_TURNSPEED = 0.2f;
	S_ACCELERATION = 1.f;
	S_TOPSPEED = 20.f;

	scene::ISceneManager* smgr = device->getSceneManager();
	node = smgr->addBillboardSceneNode(0, core::dimension2df(16.f,16.f),pos);
	node->setMaterialFlag(video::EMF_LIGHTING, false);
	node->setMaterialFlag(video::EMF_BILINEAR_FILTER, false);
	node->setMaterialTexture(0, device->getVideoDriver()->getTexture("player.png"));
	node->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF);

	return node;
}

void Racer::update(bool* keystates, f32 dt) {
	updateInput(keystates, dt);
	updateLogic(dt);
}

void Racer::updateLogic(f32 dt) {
	if(acc > 0.f) {
		speed += S_ACCELERATION*dt;
	} else {
		if(speed > 0.1f) {
			speed -= FRICTION;
		} else if(speed < -0.1f) {
			speed += FRICTION;
		} else {
			speed = 0.f;
		}
	}

	// Clamp speed to topspeed
	if(speed > S_TOPSPEED) {
		speed = S_TOPSPEED;
	} else if(speed < -S_TOPSPEED) {
		speed = -S_TOPSPEED;
	}

	dir += turn*dt*S_TURNSPEED;

	pos.X += cos(dir)*speed*dt;
	pos.Z += sin(dir)*speed*dt;
	node->setPosition(pos);
}

void Racer::updateInput(bool* keystates, f32 dt) { }
