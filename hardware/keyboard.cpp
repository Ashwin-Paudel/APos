#include "keyboard.h"

char get_input_keycode()
{

    char ch = 0;
    Port8Bit keyboardPort;
    while ((ch = keyboardPort.Read(KEYBOARD_PORT)) != 0)
    {
        if (ch > 0)
            return ch;
    }
    return ch;
}

/*
keep the cpu busy for doing nothing(nop)
so that io port will not be processed by cpu
here timer can also be used, but lets do this in looping counter
*/

void wait_for_io(uint32_t timer_count)
{
    while (5)
    {
        asm volatile("nop");
        timer_count--;

        if (timer_count <= 0)
        {
            break;
        }
    }
}

void sleep(uint32_t timer_count)
{
    wait_for_io(timer_count);
}

void enableInput()
{
    char ch = 0;
    char keycode = 0;
    do
    {
        keycode = get_input_keycode();
        if (keycode == KEY_ENTER)
        {
            pnewLine();
        }
        else
        {
            ch = get_ascii_char(keycode);
            pchar(ch);
        }
        sleep(0x02FFFFFF);
    } while (1);
}

char get_ascii_char(uint8_t key_code)
{
    switch (key_code)
    {
    case KEY_A:
        return 'A';
    case KEY_B:
        return 'B';
    case KEY_C:
        return 'C';
    case KEY_D:
        return 'D';
    case KEY_E:
        return 'E';
    case KEY_F:
        return 'F';
    case KEY_G:
        return 'G';
    case KEY_H:
        return 'H';
    case KEY_I:
        return 'I';
    case KEY_J:
        return 'J';
    case KEY_K:
        return 'K';
    case KEY_L:
        return 'L';
    case KEY_M:
        return 'M';
    case KEY_N:
        return 'N';
    case KEY_O:
        return 'O';
    case KEY_P:
        return 'P';
    case KEY_Q:
        return 'Q';
    case KEY_R:
        return 'R';
    case KEY_S:
        return 'S';
    case KEY_T:
        return 'T';
    case KEY_U:
        return 'U';
    case KEY_V:
        return 'V';
    case KEY_W:
        return 'W';
    case KEY_X:
        return 'X';
    case KEY_Y:
        return 'Y';
    case KEY_Z:
        return 'Z';
    case KEY_1:
        return '1';
    case KEY_2:
        // pdelete();
        return '2';
    case KEY_3:
        return '3';
    case KEY_4:
        return '4';
    case KEY_5:
        return '5';
    case KEY_6:
        return '6';
    case KEY_7:
        return '7';
    case KEY_8:
        return '8';
    case KEY_9:
        return '9';
    case KEY_0:
        return '0';
    case KEY_MINUS:
        return '-';
    case KEY_EQUAL:
        return '=';
    case KEY_SQUARE_OPEN_BRACKET:
        return '[';
    case KEY_SQUARE_CLOSE_BRACKET:
        return ']';
    case KEY_SEMICOLON:
        return ';';
    case KEY_BACKSLASH:
        return '\\';
    case KEY_COMMA:
        return ',';
    case KEY_DOT:
        return '.';
    case KEY_FORESLHASH:
        return '/';
    case KEY_SPACE:
        return ' ';
    default:
        return ' ';
    }
}