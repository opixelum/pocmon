#include <string.h>
#include "pokemon.h"

void print_pokemon(Pokemon* pokemon)
{
    printf("Name: %s\n", pokemon->name);
    printf("Type: %d\n", pokemon->type);
    printf("HP: %d\n", pokemon->hp);
    printf("Attack: %d\n", pokemon->attack);
    printf("Defense: %d\n", pokemon->defense);
    printf("Speed: %d\n", pokemon->speed);
}

void print_team(Team* team)
{
    for (unsigned char i = 0; i < team->size; ++i)
    {
        printf("Pokemon #%d\n", i + 1);
        print_pokemon(team->pokemons[i]);
        printf("\n");
    }
}

void print_pokedex(Pokedex* pokedex)
{
    for (unsigned char i = 0; i < pokedex->seen_pokemons; i++)
    {
        printf("Pokemon #%d\n", i + 1);
        print_pokemon(pokedex->pokemons[i]);
        printf("\n");
    }
}

Pokemon *get_pokemon_by_name(Pokedex *pokedex, char *pokemon_name)
{
    for(int i = 0; i < pokedex->nb_pokemons; i++) {
        if(strncmp((pokedex->pokemons)[i]->name, pokemon_name, strlen(pokemon_name) - 1) == 0) {
            return (pokedex->pokemons)[i];
        }
    }

    return NULL;
}
