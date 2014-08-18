#ifndef SGAMESTATEMENU_H
#define SGAMESTATEMENU_H

#include <sGameState.h>


class sGameStateMenu : public sGameState
{
    public:
        sGameStateMenu();
        virtual ~sGameStateMenu();
    protected:
    private:
        static sGameStateMenu instance;
};

#endif // SGAMESTATEMENU_H
