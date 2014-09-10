#include "sGameStateIntro.h"

using namespace irr;

sGameStateIntro sGameStateIntro::instance;

sGameStateIntro::sGameStateIntro()
{
    //ctor
}

sGameStateIntro::~sGameStateIntro()
{
    //dtor
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
sGameStateIntro* sGameStateIntro::getInstance()
{
    return &instance;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void sGameStateIntro::onInit(irr::IrrlichtDevice* initdevice)
{
    printf("activate intro\n");
    nextState=ES_NULL;
    device=initdevice;
    driver=initdevice->getVideoDriver();
    device->setWindowCaption(L"welcome - gratatata test intro");
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void sGameStateIntro::onLogic()
{
    static int tcount=0;
    tcount++;
    if(tcount>2000) setNextState(ES_PLAY);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void sGameStateIntro::onRender()
{
    driver->beginScene();
    driver->draw2DLine(core::position2di(10,10),core::position2di(400,400));
    driver->endScene();
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void sGameStateIntro::onDeactivate()
{
    printf("deactivate intro\n");
}


