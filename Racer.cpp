#include "Racer.hpp"

scene::ISceneNode* Racer::create(IrrlichtDevice* device, f32 _x, f32 _z, f32 _dir) {
	pos.X = _x;
	pos.Y = 4.f;
	pos.Z = _z;
	dir = _dir;
	i_acc = i_turn = 0.f;
	speed = xforce = zforce = 0.f;
	isSolid = true;

	// TODO: Read these from different characters
	S_TURNSPEED = 0.2f;
	S_ACCELERATION = 0.9f;
	S_TOPSPEED = 20.f;

	scene::ISceneManager* smgr = device->getSceneManager();
	node = smgr->addBillboardSceneNode(0, core::dimension2df(8.f,8.f),pos);
	node->setMaterialFlag(video::EMF_LIGHTING, false);
	node->setMaterialFlag(video::EMF_BILINEAR_FILTER, false);
	node->setMaterialTexture(0, device->getVideoDriver()->getTexture("data/textures/player.png"));
	node->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF);

	return node;
}

void Racer::update(bool* keystates, f32 dt) {
	updateInput(keystates, dt);
	updateLogic(dt);
}

void Racer::updateLogic(f32 dt) {
	dir += i_turn*S_TURNSPEED*dt;

	speed += i_acc*S_ACCELERATION*dt;
	if(speed > 0) {
		speed -= FRICTION*dt;
	} else if (speed < 0) {
		speed += FRICTION*dt;
	}
	if(speed > S_TOPSPEED) { speed = S_TOPSPEED; }

	pos.X += cos(dir)*speed*dt;
	pos.Z += sin(dir)*speed*dt;
	node->setPosition(pos);
}

void Racer::setCameraBehind(scene::ICameraSceneNode* camera) {
	f32 nx, nz;
	nx = pos.X-16.f*cos(dir);
	nz = pos.Z-16.f*sin(dir);
	camera->setPosition(core::vector3df(nx,16.f,nz));
	camera->setTarget(core::vector3df(pos.X,pos.Y+8.f,pos.Z));
}

void Racer::updateInput(bool* keystates, f32 dt) { }
