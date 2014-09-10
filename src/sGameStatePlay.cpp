#include "sGameStatePlay.h"

sGameStatePlay sGameStatePlay::instance;

sGameStatePlay::sGameStatePlay()
{
    //ctor

}

sGameStatePlay::~sGameStatePlay()
{
    //dtor
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
sGameStatePlay* sGameStatePlay::getInstance()
{
    return &instance;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void sGameStatePlay::onInit(irr::IrrlichtDevice* initdevice)
{
    nextState=ES_NULL;
    device=initdevice;
    driver=initdevice->getVideoDriver();
    smgr=initdevice->getSceneManager();
    gui=initdevice->getGUIEnvironment();
    initdevice->setEventReceiver(&gamekey);

    smgr->addCameraSceneNodeFPS();

    world=new b2World(b2Vec2(0,D_GRAVITY_DEF));

    createBackground();
    createEnemy(10,200,5);



}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void sGameStatePlay::onLogic()
{
    if(gamekey.IsKeyDown(KEY_KEY_D))    printf("move right\n");
    if(gamekey.IsKeyDown(KEY_KEY_A))    printf("move left\n");
    world->Step(0.0167f,6,2);
    update();
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void sGameStatePlay::onRender()
{
    driver->beginScene();
    smgr->drawAll();
    #ifdef __TESTDEBUG__
    debug_object(driver,world);
//    debug_object_3D(driver,world);
    #endif // __DEBUG__
    driver->endScene();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void sGameStatePlay::onDeactivate()
{

}

void sGameStatePlay::createEnemy(s32 x,s32 y,u32 stat)
{
    b2BodyDef define;
    b2PolygonShape shape;
    b2FixtureDef fixture;
    enemy.push_back(new lEnemy());

    define.type=b2_dynamicBody;
    define.fixedRotation=true;
    define.position.Set(x,y);
    define.userData=enemy.getLast();

    shape.SetAsBox(20,20);
    fixture.shape=&shape;
    fixture.filter.categoryBits=F_ENEMY_BITS;
    fixture.filter.maskBits=F_ENEMY_MASK;
    fixture.density=1;
    enemy.getLast()->body=world->CreateBody(&define);
    enemy.getLast()->body->CreateFixture(&fixture);
    enemy.getLast()->node=smgr->addCubeSceneNode(1,0,-1,
                                                 core::vector3df(x,y,1),
                                                 core::vector3df(0,0,0),
                                                 core::vector3df(20,20,1));
    enemy.getLast()->node->setMaterialFlag(EMF_LIGHTING,false);

}
void sGameStatePlay::createBullet(s32 x,s32 y,f32 angle,u32 stat)
{

}
void sGameStatePlay::createObstacle(s32 x,s32 y)
{

}
void sGameStatePlay::createBackground()
{
    fMathGenerator stageGen;
    for(s32 x=0;x<100;x+=10)
    {
        f32 y=stageGen.PerlinNoise(x,0,16);
        irr::scene::ISceneNode* node=smgr->addCubeSceneNode();
        node->setPosition(vector3df(x*2,-20-y*80,50));
        f32 width=stageGen.PerlinNoise(x,32,8);
        node->setScale(vector3df(width*10,5,width*10));
        node->setMaterialFlag(EMF_LIGHTING,false);
    }
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void sGameStatePlay::update()
{

    for(u32 i=0;i<enemy.size();i++)
    {
        lEnemy* t_enemy=enemy[i];
        core::vector3df pos;
        pos.X=t_enemy->body->GetPosition().x;
        pos.Y=t_enemy->body->GetPosition().y;
        pos.Z=CON_STAGE_DEPTH;
        t_enemy->node->setPosition(pos);
    }

    for(u32 i=0;i<bullet.size();i++)
    {
        lBullet* t_bullet=bullet[i];
        core::vector3df pos;
        pos.X=t_bullet->body->GetPosition().x;
        pos.Y=t_bullet->body->GetPosition().y;
        pos.Z=CON_STAGE_DEPTH;
        t_bullet->node->setPosition(pos);
    }
}


