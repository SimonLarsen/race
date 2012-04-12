#include "Main.hpp"

Main::Main() {
	// Set default values in case xml reading fails
	WIDTH = 800;
	HEIGHT = 600;
	// Read settings from "config.xml"
	readConfigXML();
	// Read racer stats
	Racer::readStatsXML();
	// reset all keystates
	for(int i = 0; i < KEY_KEY_CODES_COUNT; i++) {
		keystate[i] = false;
	}
}

void Main::loop() {
	u32 lastTime = device->getTimer()->getTime();

	HumanRacer pl;
	pl.create(device, 584.f,1024-110.f,0.f,0);

	while(device->run()) {
		const u32 now = device->getTimer()->getTime();
		const f32 dt = (f32)(now-lastTime) / 100.f;
		lastTime = now;

		pl.update(keystate,dt);
		pl.setCameraBehind(camera);

		driver->beginScene();
			driver->setRenderTarget(rt);
			smgr->drawAll();
			driver->setRenderTarget(0);
			driver->draw2DImage(rt, core::recti(0,0,WIDTH,HEIGHT), core::recti(0,0,256,256));

		driver->endScene();
	}
}

bool Main::init() {
	// Create Irrlicht device
	device = createDevice(video::EDT_OPENGL, core::dimension2du(WIDTH,HEIGHT));
	device->setEventReceiver(this);
	//device->setResizable(false);
	device->setWindowCaption(L"Race!");
	if(device == NULL)
		return false;

	driver = device->getVideoDriver();
	driver->setTextureCreationFlag(video::ETCF_CREATE_MIP_MAPS, false);
	smgr = device->getSceneManager();

	// Create low-res render target
	rt = driver->addRenderTargetTexture(core::dimension2du(256,256), "RTT1");

	map.load("maps/purple");
	map.createScene(device);

	camera = smgr->addCameraSceneNode();
	camera->bindTargetAndRotation(true);
	camera->setPosition(core::vector3df(512.f,10.f,512.f));

	return true;
}

bool Main::OnEvent(const SEvent& event) {
	if(event.EventType == EET_KEY_INPUT_EVENT) {
		keystate[event.KeyInput.Key] = event.KeyInput.PressedDown;
	}
	return false;
}

bool Main::isKeyDown(EKEY_CODE k) {
	return keystate[k];
}

int Main::run() {
	if(init() == false) {
		return -1;
	}

	loop();
	device->drop();
}

void Main::readConfigXML() {
	io::IrrXMLReader* xml = io::createIrrXMLReader("config.xml");
	while(xml && xml->read()) {
		switch(xml->getNodeType()) {
			case io::EXN_ELEMENT:
				// <screen width="" height="" /> tag
				if(strcmp("screen", xml->getNodeName()) == 0) {
					int newWIDTH = xml->getAttributeValueAsInt("width");
					int newHEIGHT = xml->getAttributeValueAsInt("height");
					if(newWIDTH > 0) { WIDTH = newWIDTH; }
					if(newHEIGHT > 0) { HEIGHT = newHEIGHT; }
				}
				break;
		}
	}
	delete xml;
}

int main(int argc, char** argv) {
	Main main;
	return main.run();
}
