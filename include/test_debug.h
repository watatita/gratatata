#ifndef TEST_DEBUG_H
#define TEST_DEBUG_H

#include <irrlicht.h>
#include <Box2D/Box2D.h>
using namespace irr;
using namespace core;
using namespace video;

position2di pos2convert(b2Vec2 box2dvector);
void debug_object(IVideoDriver* d_driver,b2World* d_world);
void debug_object_3D(IVideoDriver* d_driver,b2World* d_world);

#endif // TEST_DEBUG_H
