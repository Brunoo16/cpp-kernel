#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include "main.h"

class Keyboard
{
    private:
        enum KEYS
        {
            A = 0x1E,
            B = 0x30,
            C = 0x2E,
            D = 0x20,
            E = 0x12,
            F = 0x21,
            G = 0x22,
            H = 0x23,
            I = 0x17,
            J = 0x24,
            K = 0x25,
            L = 0x26,
            M = 0x32,
            N = 0x31,
            O = 0x18,
            P = 0x19,
            Q = 0x10,
            R = 0x13,
            S = 0x1F,
            T = 0x14,
            U = 0x16,
            V = 0x2F,
            W = 0x11,
            X = 0x2D,
            Y = 0x15,
            Z = 0x2C,
            _1 = 0x02,
            _2 = 0x03,
            _3 = 0x04,
            _4 = 0x05,
            _5 = 0x06,
            _6 = 0x07,
            _7 = 0x08,
            _8 = 0x09,
            _9 = 0x0A,
            _0 = 0x0B,
            SPACE = 0x39,
            OPEN_BRACKET = 0x1A,
            CLOSE_BRACKET = 0x1B,
            COMMA = 0x33,
            DOT = 0x34,
            BACKSPACE = 0x0E,
            SEMICOLON = 0x27,
            FORWARD_SLASH = 0x35,
            SLASH = 0x2B,
            ESC = 0x01,
            ENTER = 0x1C
        };

        char GetKeyCharacter(const unsigned char code);

    public:
        Keyboard();

        char GetInput();
};

#endif
