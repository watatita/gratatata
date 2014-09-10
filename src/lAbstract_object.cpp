#include "lAbstract_object.h"

lAbstract_object::lAbstract_object()
{
    //ctor
}

lAbstract_object::~lAbstract_object()
{
    //dtor
}

gameObjectType lAbstract_object::getType()
{
    return e_type;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void lAbstract_object::setSprite(u32 index)
{
    p_sprite=index;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
u32 lAbstract_object::getSprite()
{
    return p_sprite;
}

