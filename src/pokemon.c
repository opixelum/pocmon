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

Team* add_pokemon_to_team(Team *team, Pokemon *pokemon)
{
    team->size++;
    team->pokemons = realloc(team->pokemons, sizeof(Pokemon*) * team->size);
    team->pokemons[team->size - 1] = pokemon;

    return team;
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
