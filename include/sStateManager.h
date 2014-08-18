#ifndef SSTATEMANAGER_H
#define SSTATEMANAGER_H


class sStateManager
{
    public:
        sStateManager();
        virtual ~sStateManager();
        void init();
        void run();
        void nextState();
    protected:
    private:
        static sGameState* activeState;
};

#endif // SSTATEMANAGER_H
