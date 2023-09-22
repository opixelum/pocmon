#include "structs.h"
#include "battle.h"
#include "cli.h"
#include "utils.h"
#include "pokemon.h"

void start_battle(Battle *newBattle, Team *team)
{
    int choice;
    do
    {
        clear_screen();
        printf("A wild %s appeared!\n\n", newBattle->pokemon_b->name);
        printf("    1. Fight\n");
        printf("    2. Bag\n");
        printf("    3. Pokemons\n");
        printf("    4. Run\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        clear_stdin();
        switch (choice)
        {
        case 1:
            do
            {
                clear_screen();
                printf("Fight\n\n");
                printf("    1. Tackle\n");
                printf("    2. Back\n");
                printf("\nEnter your choice: ");
                scanf("%d", &choice);
                clear_stdin();
                switch (choice)
                {
                case 1:
                    clear_screen();

                    // Create bonus types
                    float bonus_types[9][9] = {
                        // NRM, FIR, WTR, PLT, ELK, GND, FLY, PSY, STL
                        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5}, // NORMAL
                        {1.0, 0.5, 0.5, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0}, // FIRE
                        {1.0, 2.0, 0.5, 0.5, 1.0, 2.0, 1.0, 1.0, 1.0}, // WATER
                        {1.0, 0.5, 2.0, 0.5, 1.0, 2.0, 0.5, 1.0, 0.5}, // PLANT
                        {1.0, 1.0, 2.0, 0.5, 0.5, 0.0, 2.0, 1.0, 1.0}, // ELECTRIC
                        {1.0, 2.0, 1.0, 0.5, 2.0, 1.0, 0.0, 1.0, 2.0}, // GROUND
                        {1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 0.5}, // FLYING
                        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 0.5}, // PSYCHIC
                        {1.0, 0.5, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5}  // STEEL
                    };

                    // Calculate bonus
                    float bonus = bonus_types[newBattle->pokemon_b->type][team->pokemons[0]->type];

                    // Calculate damage
                    printf("%s used Tackle!\n", team->pokemons[0]->name);
                    if (bonus > 1)
                    {
                        printf("It's super effective!\n");
                    }
                    else if (bonus < 1)
                    {
                        printf("It's not very effective...\n");
                    }
                    else
                    {
                        printf("Your attack worked!\n");
                    }

                    newBattle->pokemon_b->hp -= (newBattle->pokemon_b->attack - team->pokemons[0]->defense) * bonus;
                    if (newBattle->pokemon_b->hp <= 0)
                    {
                        printf("You won!\n");
                        wait_for_enter();
                        return;
                    }

                    // Calculate damage
                    printf("%s used Tackle!\n", newBattle->pokemon_b->name);
                    if (bonus > 1)
                    {
                        printf("It's super effective!\n");
                    }
                    else if (bonus < 1)
                    {
                        printf("It's not very effective...\n");
                    }
                    else
                    {
                        printf("His attack worked!\n");
                    }

                    team->pokemons[0]->hp -= (team->pokemons[0]->attack - newBattle->pokemon_b->defense) * bonus;
                    if (team->pokemons[0]->hp <= 0)
                    {
                        // Check if team->has more pokemons and use the next one if hp
                        for (int i = 1; i < team->size; i++)
                        {
                            if (team->pokemons[i]->hp >= 0)
                            {
                                Pokemon *tmp = team->pokemons[0];
                                team->pokemons[0] = team->pokemons[i];
                                team->pokemons[i] = tmp;
                                clear_stdin();
                                printf("You switched to %s!\n", team->pokemons[0]->name);
                                wait_for_enter();
                            }
                            else
                            {
                                clear_screen();
                                printf("You lost!\n");
                                wait_for_enter();

                                // Heal all pokemons
                                for (int i = 0; i < team->size; i++)
                                {
                                    team->pokemons[i]->hp = team->pokemons[i]->initial_hp;
                                }
                                printf("All your pokemons have been healed!\n");
                                return;
                            }
                        }

                        return;
                    }

                    wait_for_enter();
                    choice = 0;
                    break;
                case 2:
                    break;
                default:
                    choice = 0;
                    break;
                }
            } while (choice < 1 || choice > 2);
            break;
        case 2:
            do
            {
                clear_screen();
                printf("Bag\n\n");
                printf("    1. Pokeball\n");
                printf("    2. Potion\n");
                printf("    3. Back\n");
                printf("\nEnter your choice: ");
                scanf("%d", &choice);
                clear_stdin();
                switch (choice)
                {
                case 1:
                    do
                    {
                        clear_screen();
                        printf("Pokeball\n\n");
                        printf("    1. Do you want to catch %s ?\n", newBattle->pokemon_b->name);
                        printf("    2. Back\n");
                        printf("\nEnter your choice: ");
                        scanf("%d", &choice);
                        clear_stdin();
                        switch (choice)
                        {
                        case 1:
                            if (rand() % 3 == 0)
                            {
                                printf("You caught %s!\n", newBattle->pokemon_b->name);
                                // Add pokemon to team if under 6
                                if (team->size < 6)
                                {
                                    add_pokemon_to_team(team, newBattle->pokemon_b);
                                }
                                else
                                {
                                    // Replace a pokemon in the team
                                    do
                                    {
                                        clear_screen();
                                        printf("Your team is full, which pokemon do you want to replace?\n");
                                        print_team(team);
                                        scanf("%d", &choice);
                                        clear_stdin();
                                        if (choice > 0 && choice <= team->size)
                                        {
                                            team->pokemons[choice - 1] = newBattle->pokemon_b;
                                        }
                                    } while (choice < 1 || choice > team->size);

                                    printf("You replaced %s with %s!\n", team->pokemons[choice - 1]->name, newBattle->pokemon_b->name);
                                    break;
                                }
                                wait_for_enter();
                                return;
                            }
                            else
                            {
                                printf("You missed!\n");
                                wait_for_enter();
                                choice = 0;
                            }
                            break;

                        case 2:
                            break;

                        default:
                            choice = 0;
                            break;
                        }
                    } while (choice < 1 || choice > 2);

                    break;
                case 2:
                    do
                    {
                        clear_screen();
                        printf("Potion\n\n");
                        printf("    1. Do you want to heal %s ?", team->pokemons[0]->name);
                        printf("    2. Back\n");
                        printf("\nEnter your choice: ");
                        scanf("%d", &choice);
                        clear_stdin();
                        switch (choice)
                        {
                        case 1:
                            team->pokemons[0]->hp += team->pokemons[0]->hp / 2;
                            if (team->pokemons[0]->hp > team->pokemons[0]->initial_hp)
                            {
                                team->pokemons[0]->hp = team->pokemons[0]->initial_hp;
                            }
                            break;

                        case 2:
                            break;

                        default:
                            choice = 0;
                            break;
                        }
                    } while (choice < 1 || choice > 2);
                    break;
                case 3:
                    choice = 0;
                    break;
                default:
                    choice = 0;
                    break;
                }
            } while (choice < 1 || choice > 3);

            break;
        case 3:
            do
            {
                clear_screen();
                printf("Pokemon\n\n");
                printf("    1. Switch Pokemon\n");
                printf("    2. Back\n");
                printf("\nEnter your choice: ");
                scanf("%d", &choice);
                clear_stdin();
                switch (choice)
                {
                case 1:
                    clear_screen();
                    printf("Which pokemon do you want to switch to?\n");
                    print_team(team);
                    scanf("%d", &choice);
                    clear_stdin();
                    if (choice > 0 && choice <= team->size)
                    {
                        Pokemon *tmp = team->pokemons[0];
                        team->pokemons[0] = team->pokemons[choice - 1];
                        team->pokemons[choice - 1] = tmp;
                        printf("You switched to %s!\n", team->pokemons[0]->name);
                        wait_for_enter();
                        choice = 0;
                    }
                    else
                    {
                        printf("Invalid choice!\n");
                        wait_for_enter();
                        choice = 0;
                    }

                    break;
                case 2:
                    choice = 0;
                    break;
                default:
                    choice = 0;
                    break;
                }
            } while (choice < 1 || choice > 3);

            break;
        case 4:
            if (rand() % 2 == 0)
            {
                printf("You ran away safely!\n");
                wait_for_enter();
                return;
            }
            else
            {
                printf("You can't run away!\n");
                wait_for_enter();
                choice = 1;
            }
            break;
        default:
            choice = 0;
            break;
        }
    } while (choice < 1 || choice > 4);
}
