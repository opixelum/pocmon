#include "event_loop.h"
#include "cli.h"
#include "structs.h"
#include "map.h"

int process_user_input(char userInput,Context* context);

int event_loop(Context * context) 
{
    system ("/bin/stty raw");
    while(1) 
    {
        char input = fgetc(stdin);
        if(process_user_input(input,context) == 0) {
            system ("/bin/stty cooked");
            return 0;
        }
        system ("/bin/stty cooked");
        displayMap(context);
        system ("/bin/stty raw");
    }
}

int process_user_input(char userInput, Context* context) {
    switch(userInput) {
        case 'z':
            if(context->pos_y-1<0 || context->map[context->pos_x][context->pos_y-1]==OBSTACLE){
                break;
            }else if(context->map[context->pos_x][context->pos_y-1]==GRASS){
                // ADD SPAWN POKEMON
                context->pos_y-=1;
                break;
            }else{
                context->pos_y-=1;
                break;
            }
        case 'd':
            if(context->pos_x+1>ROWS || context->map[context->pos_x+1][context->pos_y]==OBSTACLE){
                break;
            }else if(context->map[context->pos_x+1][context->pos_y]==GRASS){
                // ADD SPAWN POKEMON
                context->pos_x+=1;
                break;
            }else{
                context->pos_x+=1;
                break;
            }
        case 's':
            if(context->pos_y+1>COLUMNS || context->map[context->pos_x][context->pos_y+1]==OBSTACLE){
                break;
            }else if(context->map[context->pos_x][context->pos_y+1]==GRASS){
                // ADD SPAWN POKEMON
                context->pos_y+=1;
                break;
            }else{
                context->pos_y+=1;
                break;
            }
        case 'q':
            if(context->pos_x-1<0 || context->map[context->pos_x-1][context->pos_y]==OBSTACLE){
                break;
            }else if(context->map[context->pos_x-1][context->pos_y]==GRASS){
                // ADD SPAWN POKEMON
                context->pos_x-=1;
                break;
            }else{
                context->pos_x-=1;
                break;
            }
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

