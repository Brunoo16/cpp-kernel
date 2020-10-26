#ifndef _ADDRESSES_H_
#define _ADDRESSES_H_

class Addresses
{
    private:
        Addresses() {}

    public:
        static unsigned long video_memory_color;
        static unsigned long video_memory_monochrome;
        static unsigned short keyboard_port;
};

#endif
