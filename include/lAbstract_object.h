#ifndef LABSTRACT_OBJECT_H
#define LABSTRACT_OBJECT_H
#include <Box2D/Box2D.h>


class lAbstract_object
{
    public:
        b2Body* body;
        lAbstract_object();
        virtual ~lAbstract_object();
        gameObjectType getType();
    protected:
        gameObjectType e_type;
    private:


};

#endif // LABSTRACT_OBJECT_H
