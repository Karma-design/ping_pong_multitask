#include "pong.h"
//Include for signals
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void my_handler_pong(int s)
{
    printf("Pong : Caught SIGINT\n");
    exit(1);
}

void pong(){

    //SIGINT handler
    struct sigaction sigIntHandler;

    sigIntHandler.sa_handler = my_handler_pong;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);

    //
    for (;;)
    {
    	/* code */
    }

}