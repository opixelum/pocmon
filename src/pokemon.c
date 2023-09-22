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

unsigned char pokemon_type_string_to_num(char *string)
{
    if (strcmp(string, "Feu") == 0) return FIRE;
    if (strcmp(string, "Eau") == 0) return WATER;
    if (strcmp(string, "Plante") == 0) return PLANT;
    if (strcmp(string, "Electrique") == 0) return ELECTRIC;
    if (strcmp(string, "Sol") == 0) return GROUND;
    if (strcmp(string, "Normal") == 0) return NORMAL;
    if (strcmp(string, "Psy") == 0) return PSY;
    if (strcmp(string, "Vol") == 0) return FLYING;
    if (strcmp(string, "Acier") == 0) return STEEL;

    return -1;
}

Pokemon **get_pokemons_from_csv()
{
    Csv *pokemon_csv = read_csv("./assets/pokemons.csv");
    if (!pokemon_csv)
    {
        fprintf(stderr, "ERROR: get_pokemons_from_csv: pokemon_csv: read_csv failed.\n");
        return NULL;
    }

    Pokemon **all_pokemons = malloc((pokemon_csv->nbRows - 1) * sizeof *all_pokemons);
    if (!all_pokemons)
    {
        fprintf(stderr, "ERROR: get_pokemons_from_csv: all_pokemons: malloc failed.\n");
    }

    for (int i = 1; i < pokemon_csv->nbRows; i++)
    {
        Pokemon *pokemon = malloc(sizeof *pokemon);
        if (!pokemon)
        {
            fprintf(stderr, "ERROR: get_pokemons_from_csv: pokemon: malloc failed.\n");
            return NULL;
        }

        pokemon->name = calloc
        (
            sizeof strlen(pokemon_csv->content[i][0] + 1),
            sizeof pokemon->name
        );
        if (!pokemon->name)
        {
            fprintf(stderr, "ERROR: get_pokemons_from_csv: pokemon->name: calloc failed.\n");
            return NULL;
        }

        strcpy(pokemon->name, pokemon_csv->content[i][0]);

        pokemon->hp = atoi(pokemon_csv->content[i][1]);
        pokemon->attack = atoi(pokemon_csv->content[i][2]);
        pokemon->defense = atoi(pokemon_csv->content[i][3]);
        pokemon->speed = atoi(pokemon_csv->content[i][4]);
        pokemon->type = pokemon_type_string_to_num(pokemon_csv->content[i][5]);

        all_pokemons[i - 1] = pokemon;
    }

    return all_pokemons;
}
