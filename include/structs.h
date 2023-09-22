#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <stdlib.h>

typedef enum TYPE
{
    NORMAL = 0,
    FIRE = 1,
    WATER = 2,
    PLANT = 3,
    ELECTRIC = 4,
    GROUND = 5,
    FLYING = 6,
    PSY = 7,
    STEEL = 8
} TYPE;

typedef enum TILE
{
    PLAYER = 'X',
    PATH = '.',
    GRASS = 'W',
    OBSTACLE = '#'
} TILE;

typedef struct Pokemon
{
    char *name;
    int initial_hp;
    int hp;
    int attack;
    int defense;
    int speed;
    TYPE type;
} Pokemon;

typedef struct Team
{
    short size;
    Pokemon **pokemons;
} Team;

typedef struct Battle
{
    Pokemon *pokemon_b;
} Battle;

typedef struct Pokedex
{
    int nb_pokemons;
    Pokemon **pokemons;
    int *seen_pokemons;
    size_t nb_seen_pokemons;
} Pokedex;

typedef struct Context
{
    int pos_x;
    int pos_y;
    TILE **map;
} Context;

typedef struct Player
{
    char *name;
    Team player_team;
} Player;

Pokemon *create_pokemon(char *name, int hp, int attack, int defense, int speed, int type);
Team *create_team();
Player *create_player(char *name);

void free_pokemon(Pokemon *pokemon);
void free_team(Team *team);
void free_player(Player *player);

#endif
