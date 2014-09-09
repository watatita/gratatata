#include "sStateManager.h"
#include "sGameStateIntro.h"
#include "sGameStateMenu.h"
#include "sGameStatePlay.h"

sGameState* sStateManager::activeState=NULL;

sStateManager::sStateManager(irr::IrrlichtDevice* tdevice)
{
    //ctor
    device=tdevice;
}

sStateManager::~sStateManager()
{
    //dtor
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void sStateManager::nextState()
{
    activeState->onDeactivate();
    switch(activeState->getNextState())
    {
        case ES_MENU:   activeState=sGameStateMenu::getInstance(); break;
        case ES_PLAY:   activeState=sGameStatePlay::getInstance(); break;
        case ES_EXIT:
            device->closeDevice();
            device->drop();
            break;
        default:        break;
    }
    if(device->run())
        activeState->onInit(device);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void sStateManager::run()
{
    while(device->run())
    {
        while((device->run()) && (activeState->getNextState()==ES_NULL))
        {
            activeState->onLogic();
            activeState->onRender();
        }
        nextState();
    }
    device->drop();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void sStateManager::init()
{
    activeState=sGameStateIntro::getInstance();
    activeState->onInit(device);
}

