#include "cli.h"
#include "event_loop.h"
#include "save.h"

int main(int argc, char **argv)
{
    test_save();
    if(event_loop() == 0) {
        return EXIT_SUCCESS;
    }
    
    return EXIT_SUCCESS;
}
