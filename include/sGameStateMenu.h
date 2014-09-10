#ifndef SGAMESTATEMENU_H
#define SGAMESTATEMENU_H

#include <sGameState.h>


class sGameStateMenu : public sGameState
{
    public:
        sGameStateMenu();
        virtual ~sGameStateMenu();
        void onInit(irr::IrrlichtDevice* initdevice);
        void onLogic();
        void onRender();
        void onDeactivate();
        static sGameStateMenu* getInstance();
    protected:
    private:
        static sGameStateMenu instance;
        irr::video::IVideoDriver* driver;
        irr::gui::IGUIEnvironment* gui;
};

#endif // SGAMESTATEMENU_H
