#include "main.h"

extern "C" void entry_point()
{
    Kernel kernel;
    kernel.PrintString("This is a test\n", VIDEO_COLOR_TABLE::WHITE);
    kernel.PrintString("Type anything below:\n", VIDEO_COLOR_TABLE::CYAN);

    Keyboard keyboard;
    bool keyPressed = false; // State to track if a key has been pressed

    while (1)
    {
        const char key = keyboard.GetInput();
        
        if (key)
        {
            if (!keyPressed) // Check if the key hasn't been pressed before
            {
                keyPressed = true; // Mark that the key has been pressed
                kernel.PrintCharacter(key, VIDEO_COLOR_TABLE::WHITE);
            }
        }
        else
        {
            keyPressed = false; // Mark that the key has been released
        }
    }
}
