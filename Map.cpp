#include "Map.hpp"

bool Map::load(core::stringc name) {
	plane_textures[0] = name + "/pl0.png";
	plane_textures[1] = name + "/pl1.png";
	plane_textures[2] = name + "/pl2.png";
	plane_textures[3] = name + "/pl3.png";

	skybox_textures[0] = name + "/sbbottom.png";
	for(int i = 1; i <= 4; i++) {
		skybox_textures[i] = name + "/sbside.png";
	}

	return true;
}

void Map::createScene(IrrlichtDevice* device) {
	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();
	smgr->clear();

	// Create ground plane
	scene::IMeshSceneNode* cube[4];
	for(int i = 0; i < 4; i++) {
		cube[i] = smgr->addCubeSceneNode(1.f);
		cube[i]->setMaterialFlag(video::EMF_LIGHTING, false);
		cube[i]->setMaterialFlag(video::EMF_BILINEAR_FILTER, false);
		cube[i]->setMaterialTexture(0, driver->getTexture(plane_textures[i]));

		cube[i]->setScale(core::vector3df(512.f,1.f,512.f));
		cube[i]->setRotation(core::vector3df(0.f,-90.f,0.f));
	}
	cube[0]->setPosition(core::vector3df(256.f, -0.5f, 768.f));
	cube[1]->setPosition(core::vector3df(768.f, -0.5f, 768.f));
	cube[2]->setPosition(core::vector3df(256.f, -0.5f, 256.f));
	cube[3]->setPosition(core::vector3df(768.f, -0.5f, 256.f));

	// Create skybox
	scene::ISceneNode* skybox = smgr->addSkyBoxSceneNode(0,
		driver->getTexture(skybox_textures[0]),
		driver->getTexture(skybox_textures[1]),
		driver->getTexture(skybox_textures[2]),
		driver->getTexture(skybox_textures[3]),
		driver->getTexture(skybox_textures[4])
	);
	skybox->setMaterialFlag(video::EMF_BILINEAR_FILTER, false);
}
