#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <stdlib.h>

typedef enum TYPE
{
    FIRE = 0,
    WATER = 1,
    PLANT = 2,
    ELECTRIC = 3,
    GROUND = 4,
    NORMAL = 5,
    PSY = 6,
    FLYING = 7, 
    STEEL = 8
}
TYPE;

typedef enum TILE
{
    PLAYER = 0,
    PATH = 1,
    GRASS = 2,
    obstacle = 3
}
TILE;

typedef struct Pokemon {
    char* name;
    int hp;
    int attack;
    int defense;
    int speed;
    TYPE type;
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
    TILE **tile;
} Map;

typedef struct Player {
    char* name;
    Team playerTeam;
} Player;

#endif
