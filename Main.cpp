#include "Main.hpp"

void Main::loop() {
	while(device->run()) {
		driver->beginScene();
		smgr->drawAll();
		driver->endScene();
	}
}

bool Main::init() {
	device = createDevice(video::EDT_OPENGL, core::dimension2du(1024,768));
	device->setWindowCaption(L"Race!");
	if(device == NULL)
		return false;

	driver = device->getVideoDriver();
	smgr = device->getSceneManager();

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
