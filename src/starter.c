#include "cli.h"
#include "structs.h"
#include "utils.h"
#include "map.h"
#include "starter.h"

void history_screen()
{
    Player *newPlayer = malloc(sizeof(Player)); // Allocate memory for the player

    // History
    clear_screen();
    printf("%ld",sizeof(TILE));
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
    starter_choose(name);
}

void starter_choose(char *name)
{
    int choice;
    char *pokemoName;
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
            break;
        case 2:
            clear_screen();
            printf("You chose Salamèche!\n");
            pokemoName = "Salamèche";
            break;
        case 3:
            clear_screen();
            printf("You chose Carapuce!\n");
            pokemoName = "Carapuce";
            break;
        case 4:
            clear_screen();
            printf("You chose Pikachu!\n");
            pokemoName = "Pikachu";
            break;
        default:
            choice = 0;
            break;
        }
    } while (choice < 1 || choice > 4);

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
    TILE** map = getMap();
    printf("%p\n",map);
    displayMap(10,10,map);
}
