#ifndef SAVE_H
#define SAVE_H

#include "structs.h"

void save_game(TILE **map, Team *team, Pokedex *pokedex);
void restore_game(TILE **map, Team *team, Pokedex *pokedex);

#endif
