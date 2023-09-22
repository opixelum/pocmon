#include "cli.h"
#include "event_loop.h"
#include "structs.h"
#include "pokemon.h"
#include "save.h"

int main(int argc, char **argv)
{
    Context *context=malloc(sizeof(Context));
    Pokedex *pokedex = get_pokedex_from_csv();
    Team *team = malloc(sizeof(Team));

    restore_game(context->map, team, pokedex);

    main_menu(context);
    
    if(event_loop(context, team, pokedex) == 0) {
        return EXIT_SUCCESS;
    }

    return EXIT_SUCCESS;
}
