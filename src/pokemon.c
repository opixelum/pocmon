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

unsigned char add_pokemon_to_pokedex(Pokemon *pokemon, Pokedex *pokedex)
{
    pokedex->pokemons = realloc(pokedex->pokemons, pokedex->seen_pokemons * sizeof pokedex->pokemons);
    if (!pokedex->pokemons) return EXIT_FAILURE;

    pokedex->pokemons[pokedex->seen_pokemons - 1] = pokemon;

    pokedex->seen_pokemons++;
    pokedex->unseen_pokemons--;

    return EXIT_SUCCESS;
} 

