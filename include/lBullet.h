#ifndef LBULLET_H
#define LBULLET_H

#include <lAbstract_object.h>


class lBullet : public lAbstract_object
{
    public:
        lBullet();
        virtual ~lBullet();

    protected:
    private:
        float angle;
        u32 frame;

};

#endif // LBULLET_H
