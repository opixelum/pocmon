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
 * @brief Add a pokemon to the team
 * 
 * @param team 
 * @param pokemon 
 * @return Team* 
 */
Team* add_pokemon_to_team(Team *team, Pokemon *pokemon);

#endif
