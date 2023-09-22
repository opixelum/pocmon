#include <string.h>
#include "structs.h"

// create all functions
Pokemon *create_pokemon(char *name, int hp, int attack, int defense, int speed, int type)
{
    Pokemon *pokemon = malloc(sizeof(Pokemon));

    pokemon->name = malloc(strlen(name) + 1);
    strcpy(pokemon->name, name);

    pokemon->initial_hp = hp;
    pokemon->hp = hp;
    pokemon->attack = attack;
    pokemon->defense = defense;
    pokemon->speed = speed;
    pokemon->type = type;

    return pokemon;
}

Team *create_team()
{
    Team *team = malloc(sizeof(Team));

    team->size = 0;
    team->pokemons = malloc(sizeof(Pokemon *));

    return team;
}

Player *create_player(char *name)
{
    Player *player = malloc(sizeof(Player));

    player->name = malloc(strlen(name) + 1);
    strcpy(player->name, name);

    return player;
}

// all free functions
void free_pokemon(Pokemon *pokemon)
{
    free(pokemon->name);
    free(pokemon);
}

void free_team(Team *team)
{
    for (int i = 0; i < team->size; i++)
    {
        free(team->pokemons[i]);
    }

    free(team);
}

void free_player(Player *player)
{
    free(player->name);
    free(player);
}
