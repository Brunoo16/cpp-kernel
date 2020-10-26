#include "keyboard.h"

Keyboard::Keyboard()
{

}

char Keyboard::GetKeyCharacter(const unsigned char code)
{
    switch(code)
    {
        case KEYS::A: return 'A';
        case KEYS::B: return 'B';
        case KEYS::C: return 'C';
        case KEYS::D: return 'D';
        case KEYS::E: return 'E';
        case KEYS::F: return 'F';
        case KEYS::G: return 'G';
        case KEYS::H: return 'H';
        case KEYS::I: return 'I';
        case KEYS::J: return 'J';
        case KEYS::K: return 'K';
        case KEYS::L: return 'L';
        case KEYS::M: return 'M';
        case KEYS::N: return 'N';
        case KEYS::O: return 'O';
        case KEYS::P: return 'P';
        case KEYS::Q: return 'Q';
        case KEYS::R: return 'R';
        case KEYS::S: return 'S';
        case KEYS::T: return 'T';
        case KEYS::U: return 'U';
        case KEYS::V: return 'V';
        case KEYS::W: return 'W';
        case KEYS::X: return 'X';
        case KEYS::Y: return 'Y';
        case KEYS::Z: return 'Z';
        case KEYS::_1: return '1';
        case KEYS::_2: return '2';
        case KEYS::_3: return '3';
        case KEYS::_4: return '4';
        case KEYS::_5: return '5';
        case KEYS::_6: return '6';
        case KEYS::_7: return '7';
        case KEYS::_8: return '8';
        case KEYS::_9: return '9';
        case KEYS::_0: return '0';
        case KEYS::SPACE: return ' ';
        case KEYS::OPEN_BRACKET: return '[';
        case KEYS::CLOSE_BRACKET: return ']';
        case KEYS::COMMA: return ',';
        case KEYS::DOT: return '.';
        case KEYS::SEMICOLON: return ';';
        case KEYS::FORWARD_SLASH: return '/';
        case KEYS::SLASH: return '\\';
        default: return 0;
    }
}

char Keyboard::GetInput()
{
    char key = 0;

    asm volatile("inb %1, %0" : "=a" (key) : "d" (Addresses::keyboard_port));

    if(key == KEYS::ENTER)
    {
        return '\n';
    }
    else
    {
        return this->GetKeyCharacter(key);
    }
}
