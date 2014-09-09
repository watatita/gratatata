#ifndef LABSTRACT_OBJECT_H
#define LABSTRACT_OBJECT_H
#include <Box2D/Box2D.h>
#include <irrlicht.h>

#define F_HERO_BITS     0b00000001
#define F_HERO_MASK     0b00010100
#define F_ENEMY_BITS    0b00000010
#define F_ENEMY_MASK    0b00011000
#define F_EBULLET_BITS  0b00000100
#define F_EBULLET_MASK  0b00010001
#define F_HBULLET_BITS  0b00001000
#define F_HBULLET_MASK  0b00010010
#define F_OBSTACLE_BITS 0b00010000
#define F_OBSTACLE_MASK 0b00001111

using namespace irr;

enum gameObjectType
{
    E_NULL,
    E_HERO,
    E_OBSTACLE,
    E_SIDEKICK,
    E_ENEMY,
    E_BULLET,
    E_HAZZARDBLOCK,
    E_SENSOR
};

class lAbstract_object
{
    public:
        b2Body* body;
        scene::ISceneNode* node;

        lAbstract_object();
        virtual ~lAbstract_object();
        gameObjectType getType();
        u32 getSprite();
        void setSprite(u32 index);
    protected:
        gameObjectType e_type;
        u32 p_sprite;
    private:


};

#endif // LABSTRACT_OBJECT_H
