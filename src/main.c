#include "cli.h"
#include "event_loop.h"
#include "structs.h"

int main(int argc, char **argv)
{
    Context* context=malloc(sizeof(Context));
    main_menu(context);
    if(event_loop(context) == 0) {
        return EXIT_SUCCESS;
    }
    
    return EXIT_SUCCESS;
}
