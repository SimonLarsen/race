#ifndef __MAIN_HPP
#define __MAIN_HPP

#include <iostream>
#include <irrlicht/irrlicht.h>
using namespace irr;

#include "Map.hpp"

class Main {
public:
	Main();
	int run();
private:
	bool init();
	void loop();

	int WIDTH, HEIGHT;

	IrrlichtDevice* device;
	video::IVideoDriver* driver;
	scene::ISceneManager* smgr;
	scene::ICameraSceneNode* camera;
	video::ITexture* rt; // Low res render target

	Map map;
};
#endif
