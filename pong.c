#include "pong.h"
//Include for signals
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "writer.h"
#include <unistd.h>

pid_t friendPidPong = 0;

//SIGNAL HANDLERS
void my_handler_pong(int s)
{
    printf("Pong : Caught SIGINT\n");
    exit(1);
}

void my_handler_usr_pong(int s)
{
    printf("Pong : I just got pinged, cpt is %i\n", a_read());
    a_write((a_read()) + 1); //cpt incrementation
    sleep(1);
    kill(friendPidPong, SIGUSR1);
}

//PONG
void pong(pid_t pid)
{
    friendPidPong = pid;

    //SIGINT handler
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = my_handler_pong;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);

    //SIGUSR1 handler
    struct sigaction sigUsrHandler;
    sigUsrHandler.sa_handler = my_handler_usr_pong;
    sigemptyset(&sigUsrHandler.sa_mask);
    sigUsrHandler.sa_flags = 0;
    sigaction(SIGUSR1, &sigUsrHandler, NULL);

    //Infinite loop
    for (;;)
    {
        /* code */
    }

}