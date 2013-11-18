#include "ping.h"
//Include for signals
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void my_handler_ping(int s)
{
    printf("Ping : Caught SIGINT\n");
    exit(1);
}

void ping(){

    //SIGINT handler
    struct sigaction sigIntHandler;

    sigIntHandler.sa_handler = my_handler_ping;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);

    //
    for (;;)
    {
    	/* code */
    }

}