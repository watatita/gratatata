#include "kEventReceiver.h"

kEventReceiver::kEventReceiver()
{
    //ctor
    for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
        KeyIsDown[i] = false;
}

kEventReceiver::~kEventReceiver()
{
    //dtor
}

bool kEventReceiver::OnEvent(const SEvent& event)
{
        // Remember whether each key is down or up
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    return false;
}

bool kEventReceiver::IsKeyDown(EKEY_CODE keyCode) const
{
    return KeyIsDown[keyCode];
}
