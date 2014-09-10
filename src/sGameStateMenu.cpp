#include "sGameStateMenu.h"
using namespace irr;
using namespace core;
sGameStateMenu sGameStateMenu::instance;

sGameStateMenu::sGameStateMenu()
{
    //ctor
}

sGameStateMenu::~sGameStateMenu()
{
    //dtor
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
sGameStateMenu* sGameStateMenu::getInstance()
{
    return &instance;
}



/** @brief (one liner)
  *
  * (documentation goes here)
  */
void sGameStateMenu::onInit(irr::IrrlichtDevice* initdevice)
{
    printf("activate menu\n");
    nextState=ES_NULL;
    driver=initdevice->getVideoDriver();
    gui=initdevice->getGUIEnvironment();

    gui->addStaticText(L"welcome to gratatata menu",core::recti(20,20,120,60));
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void sGameStateMenu::onLogic()
{

}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void sGameStateMenu::onRender()
{
    driver->beginScene(true,true,video::SColor(0xff,0xff,0xff,0xaa));
    driver->draw2DRectangle(video::SColor(0xff,0xff,0,0),recti(100,100,300,300));
    gui->drawAll();
    driver->endScene();
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void sGameStateMenu::onDeactivate()
{
    printf("deactivate menu\n");
    gui->drop();
}
