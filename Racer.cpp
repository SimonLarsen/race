#include "Racer.hpp"

scene::ISceneNode* Racer::create(IrrlichtDevice* device, f32 _x, f32 _z, f32 _dir, int racer) {
	pos.X = _x;
	pos.Y = 4.f;
	pos.Z = _z;
	dir = _dir;
	i_acc = i_turn = 0.f;
	speed = xforce = zforce = 0.f;
	isSolid = true;

	// TODO: Read these from different characters
	S_ACCELERATION = RACER_STATS[racer][0];
	S_TOPSPEED = RACER_STATS[racer][1];
	S_TURNSPEED = RACER_STATS[racer][2];

	scene::ISceneManager* smgr = device->getSceneManager();
	node = smgr->addBillboardSceneNode(0, core::dimension2df(8.f,8.f),pos);
	node->setMaterialFlag(video::EMF_LIGHTING, false);
	node->setMaterialFlag(video::EMF_BILINEAR_FILTER, false);
	node->setMaterialTexture(0, device->getVideoDriver()->getTexture("data/textures/moonman.png"));
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

void Racer::readStatsXML() {
	io::IrrXMLReader* xml = 0;

	for(int i = 0; i < NUM_PLAYERS; i++) {
		xml = io::createIrrXMLReader(PLAYER_FILES[i]);
		while(xml && xml->read()) {
			switch(xml->getNodeType()) {
				case io::EXN_ELEMENT:
					// <stats ... />
					if(strcmp("stats", xml->getNodeName()) == 0) {
						f32 acceleration = xml->getAttributeValueAsFloat("acceleration");
						f32 topspeed = xml->getAttributeValueAsFloat("topspeed");
						f32 turnspeed = xml->getAttributeValueAsFloat("turnspeed");
						std::cout << acceleration << std::endl;
						std::cout << topspeed << std::endl;
						std::cout << turnspeed << std::endl;

						if(acceleration > 0) { RACER_STATS[i][0] = acceleration; }
						if(topspeed > 0) { RACER_STATS[i][1] = topspeed; }
						if(turnspeed > 0) { RACER_STATS[i][2] = turnspeed; }
					}
					break;
			}
		}
		
		delete xml;
	}
}

void Racer::updateInput(bool* keystates, f32 dt) { }
