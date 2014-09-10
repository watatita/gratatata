#ifndef LHERO_H
#define LHERO_H

#include <lAbstract_object.h>


class lHero : public lAbstract_object
{
    public:
        lHero();
        virtual ~lHero();

    private:
        bool direction;
        u32 frame;

};

#endif // LHERO_H
