#ifndef KEVENTRECEIVER_H
#define KEVENTRECEIVER_H

#include <irrlicht.h>
/*from irrlicht event receiver example*/
using namespace irr;

class kEventReceiver : public IEventReceiver
{
    public:
        kEventReceiver();
        virtual ~kEventReceiver();
        bool OnEvent(const SEvent& event);
        bool IsKeyDown(EKEY_CODE keyCode) const;
    private:
        bool KeyIsDown[KEY_KEY_CODES_COUNT];

};

#endif // KEVENTRECEIVER_H
