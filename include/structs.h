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

typedef struct Pokemon
{
    char* name;
    int hp;
    int attack;
    int defense;
    int speed;
    TYPE type;
}
Pokemon;

typedef struct Team
{
    short size;
    Pokemon** pokemons;
}
Team;

typedef struct Battle
{
    Pokemon pokemon_a;
    Pokemon pokemon_b;
}
Battle;

typedef struct Pokedex
{
    Pokemon** pokemons;
    int seen_pokemons;
    int unseen_pokemons;
}
Pokedex;

typedef struct Map
{
    int columns;
    int lines;
    TILE **tile;
}
Map;

typedef struct Player
{
    char* name;
    Team player_team;
}
Player;

Pokemon* create_pokemon(char* name, int hp, int attack, int defense, int speed, int type);
Team* create_team();
Player* create_player(char* name);

void free_pokemon(Pokemon* pokemon);
void free_team(Team* team);
void free_player(Player* player);

#endif
