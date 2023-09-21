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

/**
 * @brief Add a pokemon to a pokedex
 * @param pokemon The pokemon to add
 * @param pokedex The pokedex to add a pokemon to
 * @return 0 if successful, 1 otherwise
 */
unsigned char add_pokemon_to_pokedex(Pokemon *pokemon, Pokedex *pokedex);

#endif
