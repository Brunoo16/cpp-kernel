#ifndef _KERNEL_H_
#define _KERNEL_H_

#include "main.h"

#define VIDEO_WIDTH 80
#define VIDEO_HEIGHT 25

class Kernel
{
    private:
        unsigned short* video_buffer;
        unsigned int current_pos;
        unsigned int current_line;

    public:
        Kernel();

        unsigned short VideoEntry(const unsigned char character, const unsigned char color);
        void ClearVideoBuffer(const unsigned char color);
        void PrintString(const char* str, const unsigned char color);
        void PrintCharacter(const char character, const unsigned char color);
};

#endif
