#include "cli.h"
#include "event_loop.h"

int main(int argc, char **argv)
{
    if(event_loop() == 0) {
        return EXIT_SUCCESS;
    }
    
    return EXIT_SUCCESS;
}
