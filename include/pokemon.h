#ifndef POKEMON_H
#define POKEMON_H

#include "structs.h"

/**
 * @brief Prints a pokemon's stats
 */
void print_pokemon(Pokemon* pokemon);

/**
 * @brief Prints a team's pokemons
 */
void print_team(Team* team);

/**
 * @brief Prints all pokemons in a pokedex
 */
void print_pokedex(Pokedex* pokedex);

Pokemon *get_pokemon_by_name(Pokedex *pokedex, char *pokemon_name);

#endif
