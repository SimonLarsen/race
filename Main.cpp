#include "Main.hpp"

Main::Main() {
	WIDTH = 1024;
	HEIGHT = 768;
}

void Main::loop() {
	while(device->run()) {
		driver->beginScene();
		driver->setRenderTarget(rt);
		smgr->drawAll();
		driver->setRenderTarget(0);
		driver->draw2DImage(rt, core::recti(0,0,WIDTH,HEIGHT), core::recti(0,0,256,256));
		driver->endScene();
	}
}

bool Main::init() {
	device = createDevice(video::EDT_OPENGL, core::dimension2du(WIDTH,HEIGHT));
	device->setWindowCaption(L"Race!");
	if(device == NULL)
		return false;

	driver = device->getVideoDriver();
	driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, false);
	smgr = device->getSceneManager();

	rt = driver->addRenderTargetTexture(core::dimension2du(256,256), "RTT1");

	map.load("maps/purple");
	map.createScene(device);

	camera = smgr->addCameraSceneNodeFPS();

	HumanRacer r;
	r.create(device, 512.f,512.f,0.f);

	return true;
}

int Main::run() {
	if(init() == false) {
		return -1;
	}

	loop();
}

int main(int argc, char** argv) {
	Main main;
	return main.run();
}
