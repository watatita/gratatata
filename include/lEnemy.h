#ifndef LENEMY_H
#define LENEMY_H

#include <lAbstract_object.h>


class lEnemy : public lAbstract_object
{
    public:
        lEnemy();
        virtual ~lEnemy();

    protected:
    private:
        bool direction;
        u32 frame;

};

#endif // LENEMY_H
