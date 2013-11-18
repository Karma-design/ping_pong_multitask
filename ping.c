#include "ping.h"
//Include for signals
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "writer.h"

pid_t friendPid = 0;

void my_handler_int_ping(int s)
{
    printf("Ping : Caught SIGINT\n");
    exit(1);
}

void my_handler_usr_ping(int s)
{
    printf("I just got ponged\n");
    a_write((a_read())+1); //cpt incrementation
    kill(friendPid, SIGUSR1);
}

void ping(pid_t pid)
{
    friendPid = pid;
    //SIGINT handler
    struct sigaction sigIntHandler;

    sigIntHandler.sa_handler = my_handler_int_ping;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);
    //SIGUSR1 handler
    struct sigaction sigUsrHandler;

    sigUsrHandler.sa_handler = my_handler_usr_ping;
    sigemptyset(&sigUsrHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    sigaction(SIGUSR1, &sigUsrHandler, NULL);

    printf("Je suis ping (%i) et voilà le pid de mon coupain : %i\n", getpid(), friendPid);
    //
    //Sending first signal
    a_write(1);
    kill(friendPid, SIGUSR1);
    for (;;)
    {
        /* code */
    }

}