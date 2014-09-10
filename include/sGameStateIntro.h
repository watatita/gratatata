#ifndef SGAMESTATEINTRO_H
#define SGAMESTATEINTRO_H

#include <sGameState.h>

class sGameStateIntro : public sGameState
{
    public:
        sGameStateIntro();
        virtual ~sGameStateIntro();
        void onInit(irr::IrrlichtDevice* initdevice);
        void onLogic();
        void onRender();
        void onDeactivate();
        static sGameStateIntro* getInstance();
    protected:
    private:
        static sGameStateIntro instance;
        irr::video::IVideoDriver* driver;
};

#endif // SGAMESTATEINTRO_H
