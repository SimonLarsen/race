#ifndef __MAIN_HPP
#define __MAIN_HPP

#include <irrlicht/irrlicht.h>
using namespace irr;

class Main {
public:
	int run();
private:
	bool init();
	void loop();

	IrrlichtDevice* device;
	video::IVideoDriver* driver;
	scene::ISceneManager* smgr;
};
#endif
