#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @brief Clears stdin buffer (useful before getting user input)
 *
 * When calling getchar(), it clears a character from stdin buffer.
 * While it's not a newline character, or EOF, it keeps clearing characters.
 */
void clear_stdin();

/**
 * @brief Get the user input from stdin
 *
 * @return Pointer to the string or character containing user input
 */
char *get_user_input();

#endif
