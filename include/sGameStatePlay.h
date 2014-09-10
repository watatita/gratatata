#ifndef SGAMESTATEPLAY_H
#define SGAMESTATEPLAY_H

#include <sGameState.h>


class sGameStatePlay : public sGameState
{
    public:
        sGameStatePlay();
        virtual ~sGameStatePlay();
    protected:
    private:
        static sGameStatePlay instance;
};

#endif // SGAMESTATEPLAY_H
