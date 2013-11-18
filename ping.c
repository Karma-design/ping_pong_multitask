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

void ping(pid_t pid){

    //SIGINT handler
    struct sigaction sigIntHandler;

    sigIntHandler.sa_handler = my_handler_ping;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);
    printf("Je suis ping (%i) et voilà le pid de mon coupain : %i\n",getpid(),pid);
    //
    for (;;)
    {
    	/* code */
    }

}