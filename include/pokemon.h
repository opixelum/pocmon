#ifndef POKEMON_H
#define POKEMON_H

#include "structs.h"
#include "files.h"
#include "string.h"

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

/**
 * @brief Get all pokemons listed in csv file
 * @return An array of pokemons
 * @warning Free the returned array after use
 */
Pokemon **get_pokemons_from_csv();

/**
 * @brief Convert pokemon type from string to number (unsigned char)
 * @param string Type in string
 * @return The corresponding type in integer
 */
unsigned char pokemon_type_string_to_num(char *string);
Pokemon *get_pokemon_by_name(Pokedex *pokedex, char *pokemon_name);

#endif
