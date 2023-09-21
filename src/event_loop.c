#include "event_loop.h"
#include "cli.h"

int process_user_input(char userInput);

int event_loop() 
{
    system ("/bin/stty raw");
    while(1) 
    {
        char input = fgetc(stdin);
        if(process_user_input(input) == 0) {
            system ("/bin/stty cooked");
            return 0;
        }
        // TODO: print map
    }
}

int process_user_input(char userInput) {
    switch(userInput) {
        case 'z':
            // TODO: move up
            break;
        case 'd':
            // TODO: move right
            break;
        case 's':
            // TODO: move down
            break;
        case 'q':
            // TODO: move left
            break;
        case 'e':
            // TODO: show pokemons
            break;
        case 'S':
            // TODO: save game
            break;
        case 'Q':
            // exits program
            return 0;
    }
}

