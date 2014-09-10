#ifndef SGAMESTATE_H
#define SGAMESTATE_H
#include <irrlicht.h>

enum eGameStates
{
    ES_NULL,
    ES_INTRO,
    ES_MENU,
    ES_PLAY,
    ES_EXIT
};

class sGameState
{
    public:
        sGameState();
        virtual ~sGameState();
        virtual void onInit(irr::IrrlichtDevice* initdevice) = 0;
        virtual void onLogic() = 0;
        virtual void onRender() = 0;
        virtual void onDeactivate() = 0;
    protected:
        irr::IrrlichtDevice* device;
        int nextState;
    private:
};

#endif // SGAMESTATE_H
