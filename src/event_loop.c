#include "event_loop.h"
#include "cli.h"
#include "structs.h"
#include "map.h"
#include "save.h"
#include "battle.h"
#include "pokemon.h"

int process_user_input(char userInput, Context* context, Team *team, Pokedex *pokedex);
int trigger_fight();
Battle *random_battle(Pokedex *pokedex);

int event_loop(Context * context, Team *team, Pokedex *pokedex)
{
    system ("/bin/stty raw");
    while(1) 
    {
        char input = fgetc(stdin);
        if(process_user_input(input,context, team, pokedex) == 0) {
            system ("/bin/stty cooked");
            return 0;
        }
        system ("/bin/stty cooked");
        displayMap(context);
        system ("/bin/stty raw");
    }
}

int process_user_input(char userInput, Context* context, Team *team, Pokedex *pokedex) 
{
    switch(userInput) {
        case 'z':
            if(context->pos_y-1<0 || context->map[context->pos_x][context->pos_y-1]==OBSTACLE){
                break;
            }else if(context->map[context->pos_x][context->pos_y-1]==GRASS){
                if(trigger_fight()) {
                    system ("/bin/stty cooked");
                    start_battle(random_battle(pokedex), team);
                    system ("/bin/stty raw");
                }
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
                if(trigger_fight()) {
                    system ("/bin/stty cooked");
                    start_battle(random_battle(pokedex), team);
                    system ("/bin/stty raw");
                }
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
                if(trigger_fight()) {
                    system ("/bin/stty cooked");
                    start_battle(random_battle(pokedex), team);
                    system ("/bin/stty raw");
                }
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
                if(trigger_fight()) {
                    system ("/bin/stty cooked");
                    start_battle(random_battle(pokedex), team);
                    system ("/bin/stty raw");
                }
                context->pos_x-=1;
                break;
            }else{
                context->pos_x-=1;
                break;
            }
        case 'e':
            system ("/bin/stty cooked");
            clear_screen();
            print_team(team);
            wait_for_enter();
            system ("/bin/stty raw");

            break;
        case 'S':
            save_game(context->map, team, pokedex);
            break;
        case 'Q':
            // exits program
            return 0;
    }

    return 1;

}

int trigger_fight() 
{
    srand(time(NULL));
    int random = rand() % 10;

    return random == 0;
}

Battle *random_battle(Pokedex *pokedex) 
{
    Battle *battle = malloc(sizeof(Battle));

    srand(time(NULL));
    int random = rand() % pokedex->nb_pokemons - 1;

    battle->pokemon_b = pokedex->pokemons[random];

    return battle;
}
