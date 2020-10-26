#include "kernel.h"

Kernel::Kernel()
{
    this->video_buffer = reinterpret_cast<unsigned short*>(Addresses::video_memory_color);
    this->ClearVideoBuffer(VIDEO_COLOR_TABLE::WHITE);
}

unsigned short Kernel::VideoEntry(const unsigned char character, const unsigned char color)
{
    return static_cast<unsigned short>(character) | color << 8;
}

void Kernel::ClearVideoBuffer(const unsigned char color)
{
    for(unsigned char i = 0; i < VIDEO_HEIGHT; ++i)
    {
        for(unsigned char j = 0; j < VIDEO_WIDTH; ++j)
        {
            this->video_buffer[i * VIDEO_WIDTH + j] = this->VideoEntry(' ', color);
        }
    }
    this->current_line = 0;
    this->current_pos = 0;
}

void Kernel::PrintString(const char* str, const unsigned char color)
{
    unsigned long length = 0;

    while(str[length])
    {
        if(str[length] == '\n')
        {
            this->current_line++;
            this->current_pos = VIDEO_WIDTH * this->current_line - 1;
        }
        else
        {
            this->video_buffer[(this->current_line * VIDEO_WIDTH + this->current_pos)] = this->VideoEntry(str[length], color);
        }

        if(++this->current_pos == VIDEO_WIDTH)
        {
            this->current_pos = 0;

            if(++this->current_line == VIDEO_HEIGHT)
            {
                this->current_line = 0;
            }
        }
        length++;
    }
}

void Kernel::PrintCharacter(const char character, const unsigned char color)
{
    if(character == '\n')
    {
        this->current_line++;
        this->current_pos = VIDEO_WIDTH * this->current_line - 1;
    }
    else
    {
        this->video_buffer[(this->current_line * VIDEO_WIDTH + this->current_pos)] = this->VideoEntry(character, color);
    }

    if(++this->current_pos == VIDEO_WIDTH)
    {
        this->current_pos = 0;

        if(++this->current_line == VIDEO_HEIGHT)
        {
            this->current_line = 0;
        }
    }
}
