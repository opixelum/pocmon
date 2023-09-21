#include <stdio.h>
#include <stdlib.h>

typedef struct Pokemon {
    char* name;
    int pv;
    int attack;
    int defense;
    int speed;
    int type;
} Pokemon;

typedef struct Team {
    short size;
    Pokemon** pokemons;
} Team;

typedef struct Battle {
    Pokemon pokemonA;
    Pokemon pokemonB;
} Battle;

typedef struct Pokedex {
    Pokemon** pokemons;
    int seenPokemons;
    int unseenPokemons;
} Pokedex;

typedef struct Map {
    int columns;
    int lines;
    enum tile {player, path, grass, obstacle};
} Map;

typedef struct Player {
    char* name;
    Team playerTeam;
} Player;

Pokemon* create_pokemon(char* name, int pv, int attack, int defense, int speed, int type);
Team* create_team();
Player* create_player(char* name);

void free_pokemon(Pokemon* pokemon);
void free_team(Team* team);
void free_player(Player* player);
