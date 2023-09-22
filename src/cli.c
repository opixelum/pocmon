#include "cli.h"
#include "starter.h"
#include "map.h"

void clear_screen()
{
    printf("\e[1;1H\e[2J");
}

void clear_lines(int lines)
{
    for (int i = 0; i < lines; ++i)
        printf("\x1b[1F\x1b[2K");
}

void main_menu(Context* context)
{
    int choice;
    do
    {
        clear_screen();
        printf("PoCmon\n\n    1. New Game\n    2. Continue Game\n    3. Quit\n\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        clear_stdin();
        switch (choice)
        {
        case 1:
            history_screen(context);
            break;
        case 2:
            if(getMap(context)!=0){
                history_screen(context);
            }
            break;
        case 3:
            printf("Quit\n");
            break;
        default:
            choice = 0;
            break;
        }
    } while (choice < 1 || choice > 3);
}

void wait_for_enter()
{
    printf("\nPress [ENTER] to continue...");
    clear_stdin();
}
