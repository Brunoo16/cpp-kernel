#include "main.h"

extern "C" void entry_point()
{
    Kernel kernel;
    kernel.PrintString("This is a test\n", VIDEO_COLOR_TABLE::WHITE);
    kernel.PrintString("Type anything below:\n", VIDEO_COLOR_TABLE::CYAN);

    //Keyboard keyboard; - Gotta fix input later...

    while(1) // Your kernel logic goes here...
    {
        /*const char key = keyboard.GetInput();
        if(key)
        {
            kernel.PrintCharacter(key, VIDEO_COLOR_TABLE::WHITE);
        }*/
    }
}
