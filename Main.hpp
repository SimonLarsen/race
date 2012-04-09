#ifndef __MAIN_HPP
#define __MAIN_HPP

#include <iostream>
#include <irrlicht/irrlicht.h>
using namespace irr;
#include <irrlicht/irrXML.h>

#include "Map.hpp"
#include "Racer.hpp"
#include "HumanRacer.hpp"

class Main : public IEventReceiver {
public:
	Main();
	int run();
	bool OnEvent(const SEvent& event);
	bool isKeyDown(EKEY_CODE k);
private:
	bool init();
	void loop();
	void readConfigXML();

	int WIDTH, HEIGHT;
	bool keystate[KEY_KEY_CODES_COUNT];

	IrrlichtDevice* device;
	video::IVideoDriver* driver;
	scene::ISceneManager* smgr;
	scene::ICameraSceneNode* camera;
	video::ITexture* rt; // Low res render target

	Map map;
	Racer racer[8];
};
#endif
