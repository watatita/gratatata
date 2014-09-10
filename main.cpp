
#include <irrlicht.h>
#include <sStateManager.h>

using namespace irr;


using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main(int argc, char** argv)
{

    IrrlichtDevice *device =
        createDevice(EDT_OPENGL, dimension2d<u32>(640, 480), 16,
            false, false, false, 0);
    #ifdef __TESTDEBUG__
    printf("its debug\n");
    #endif // __DEBUG__
    sStateManager testGame(device);
    testGame.init();
    testGame.run();

    return 0;
}

