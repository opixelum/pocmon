#include "cli.h"

void clear_screen()
{
    printf("\e[1;1H\e[2J");
}

void clear_lines(int lines)
{
    for (int i = 0; i < lines; ++i) printf("\x1b[1F\x1b[2K");
}

void main_menu()
{
    printf("PoCmon\n\n    1. New Game\n    2. Continue Game\n    3. Quit\n\n");
}

void wait_for_enter()
{
    printf("\nPress [ENTER] to continue...");
    clear_stdin();
}
