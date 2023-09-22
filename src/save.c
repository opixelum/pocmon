#include "save.h"
#include "pokemon.h"

int save_pokedex(Pokedex *pokedex);
int restore_pokedex(Pokedex *pokedex);
int save_team(Team *team);
int restore_team(Team *team, Pokedex *pokedex);

void test_save()
{
    Team *team = malloc(sizeof(Team));

    Pokemon *pikachu = create_pokemon("Pikachu", 100, 100, 100, 100, ELECTRIC);
    Pokemon *bulbasaur = create_pokemon("Bulbasaur", 100, 100, 100, 100, GRASS);

    Pokedex pokedex = {
        .nb_seen_pokemons = 2,
        .nb_pokemons = 2
    };

    pokedex.pokemons = malloc(sizeof(Pokemon*) * 2);
    pokedex.pokemons[0] = pikachu;
    pokedex.pokemons[1] = bulbasaur;

    pokedex.seen_pokemons = malloc(sizeof(int) * 2);
    pokedex.seen_pokemons[0] = 0;
    pokedex.seen_pokemons[1] = 1;

    restore_team(team, &pokedex);

    printf("\n%s %s", team->pokemons[0]->name, team->pokemons[1]->name);
}

void save_game(TILE **map, Team *team, Pokedex *pokedex) 
{
    restore_team(team, pokedex);
}

void restore_game(TILE **map, Team *team, Pokedex *pokedex) 
{

}

int save_team(Team *team) 
{
    FILE *team_save = fopen("../save/team.save", "w");

    if(team_save == NULL) {
        return 1;
    }

    for(int i = 0; i < team->size; i++) {
        fprintf(team_save, "%s\n", (team->pokemons)[i]->name);
    }

    fclose(team_save);

    return 0;
}

int restore_team(Team *team, Pokedex *pokedex) 
{
    char line[1024];
    FILE *team_save = fopen("../save/team.save", "r");

    if(team_save == NULL) {
        return EXIT_FAILURE;
    }

    team->pokemons = malloc(0);
    team->size = 0;

    while(fgets(line, 1024, team_save)) {
        Pokemon *foundPokemon = get_pokemon_by_name(pokedex, line);
        if(!foundPokemon) {
            continue;
        }

        team->pokemons = realloc(team->pokemons, (team->size + 1) * sizeof(Pokemon *));

        team->pokemons[team->size] = foundPokemon;
        (team->size)++;
    }

    return EXIT_SUCCESS;
}

int save_pokedex(Pokedex *pokedex)
{
    FILE *pokedex_save = fopen("../save/pokedex.save", "w");

    if(pokedex_save == NULL) {
        return 1;
    }

    for(int i = 0; i < pokedex->nb_seen_pokemons; i++) {
        fprintf(pokedex_save, "%d\n", pokedex->seen_pokemons[i]);
    }

    fclose(pokedex_save);

    return 0;
}

int restore_pokedex(Pokedex *pokedex) {
    char line[1024];
    FILE *pokedex_save = fopen("../save/pokedex.save", "r");

    if(pokedex_save == NULL) {
        return EXIT_FAILURE;
    }

    pokedex->seen_pokemons = malloc(0);
    pokedex->nb_seen_pokemons = 0;

    while(fgets(line, 1024, pokedex_save)) {
        pokedex->seen_pokemons = realloc(pokedex->seen_pokemons, (pokedex->nb_seen_pokemons + 1) * sizeof(int));
        pokedex->seen_pokemons[pokedex->nb_seen_pokemons] = atoi(line);
        (pokedex->nb_seen_pokemons)++;
    }

    return EXIT_SUCCESS;
}
