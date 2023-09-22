#include "cli.h"
#include "structs.h"
#include "utils.h"
#include "starter.h"
#include "map.h"
#include "pokemon.h"
#include "battle.h"

void history_screen(Context *context)
{
    Player *newPlayer = malloc(sizeof(Player)); // Allocate memory for the player

    // History
    clear_screen();
    printf("%ld", sizeof(TILE));
    printf("Professor Chen: Hello there! Welcome to the world of Pokemon!\n");
    wait_for_enter();
    clear_screen();
    printf("My name is Chen! People call me the Pokemon Prof!\n");
    wait_for_enter();
    clear_screen();
    printf("This world is inhabited by creatures called Pokemon!\n");
    wait_for_enter();
    clear_screen();
    printf("For some people, Pokemon are pets. Others use them for fights.\n");
    wait_for_enter();
    clear_screen();
    printf("Myself...I study Pokemon as a profession.\n");
    wait_for_enter();
    clear_screen();
    printf("First, what is your name?\n");
    printf("Enter your name: ");
    char name[20];
    scanf("%s", name);
    clear_stdin();
    clear_screen();
    newPlayer->name = name;
    printf("Right! So your name is %s!\n", name);
    wait_for_enter();
    clear_screen();
    printf("%s, your very own Pokemon legend is about to unfold!\n", name);
    wait_for_enter();
    clear_screen();
    printf("A world of dreams and adventures with Pokemon awaits! Let's go!\n");
    wait_for_enter();
    clear_screen();
    starter_choose(name, context);
}

void starter_choose(char *name, Context *context)
{
    int choice;
    char *pokemoName;
    Pokemon *pokemon = malloc(sizeof(Pokemon));
    do
    {
        clear_screen();
        printf("Professor Chen: Now, %s, which Pokemon do you want?\n\n", name);
        printf("    1. Bulbizzare\n");
        printf("    2. Salamèche\n");
        printf("    3. Carapuce\n");
        printf("    4. Pikachu\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        clear_stdin();
        switch (choice)
        {
        case 1:
            clear_screen();
            printf("You chose Bulbizzare!\n");
            pokemoName = "Bulbizzare";
            pokemon = create_pokemon(pokemoName, 90, 49, 24, 45, PLANT);
            break;
        case 2:
            clear_screen();
            printf("You chose Salamèche!\n");
            pokemoName = "Salamèche";
            pokemon = create_pokemon(pokemoName, 78, 52, 21, 65, FIRE);
            break;
        case 3:
            clear_screen();
            printf("You chose Carapuce!\n");
            pokemoName = "Carapuce";
            pokemon = create_pokemon(pokemoName, 88, 48, 32, 43, WATER);
            break;
        case 4:
            clear_screen();
            printf("You chose Pikachu!\n");
            pokemoName = "Pikachu";
            pokemon = create_pokemon(pokemoName, 70, 55, 20, 90, ELECTRIC);
            break;
        default:
            choice = 0;
            break;
        }
    } while (choice < 1 || choice > 4);

    Team *team = create_team();
    add_pokemon_to_team(team, pokemon);

    wait_for_enter();
    clear_screen();
    printf("Professor Chen: I see! This Pokemon is really energetic!\n");
    wait_for_enter();
    clear_screen();
    printf("Professor Chen: %s, take care of %s!\n", name, pokemoName);
    wait_for_enter();
    clear_screen();
    printf("Professor Chen: %s, you are ready to go!\n", name);

    // Init the map
    mapInit();
    getMap(context);
}
