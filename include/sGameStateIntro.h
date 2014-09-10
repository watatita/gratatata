#ifndef SGAMESTATEINTRO_H
#define SGAMESTATEINTRO_H

#include <sGameState.h>


class sGameStateIntro : public sGameState
{
    public:
        sGameStateIntro();
        virtual ~sGameStateIntro();
    protected:
    private:
        static sGameStateIntro instance;
};

#endif // SGAMESTATEINTRO_H
