#ifndef SSTATEMANAGER_H
#define SSTATEMANAGER_H

#include <sGameState.h>
#include <irrlicht.h>

class sStateManager
{
    public:
        sStateManager(irr::IrrlichtDevice* tdevice);
        virtual ~sStateManager();
        void init();
        void run();
    protected:
    private:
        void nextState();
        static sGameState* activeState;
        irr::IrrlichtDevice* device;
};

#endif // SSTATEMANAGER_H
