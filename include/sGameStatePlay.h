#ifndef SGAMESTATEPLAY_H
#define SGAMESTATEPLAY_H

#include <Box2D/Box2D.h>
#include <sGameState.h>
#include <lBullet.h>
#include <lEnemy.h>
#include <lHero.h>
#include <lObstacle.h>
#include <kEventReceiver.h>
#include <fMathGenerator.h>

#ifdef  __TESTDEBUG__
#include <test_debug.h>
#endif // __DEBUG__

#define D_GRAVITY_DEF   -1
#define CON_STAGE_DEPTH 1

using namespace irr;

class sGameStatePlay : public sGameState
{
    public:
        sGameStatePlay();
        virtual ~sGameStatePlay();
        void onInit(IrrlichtDevice* initdevice);
        void onLogic();
        void onRender();
        void onDeactivate();
        static sGameStatePlay* getInstance();
    protected:
    private:
        static sGameStatePlay instance;
        irr::video::IVideoDriver* driver;
        irr::scene::ISceneManager* smgr;
        irr::gui::IGUIEnvironment* gui;
        IrrlichtDevice* device;
        kEventReceiver gamekey;
        b2World* world;
        core::array<lEnemy*> enemy;
        core::array<lBullet*> bullet;
        core::array<lObstacle*> ground;
        lHero* hero;

        void createEnemy(s32 x,s32 y,u32 stat);
        void createBullet(s32 x,s32 y,f32 angle,u32 stat);
        void createObstacle(s32 x,s32 y);
        void createBackground();

        void update();
};

#endif // SGAMESTATEPLAY_H
