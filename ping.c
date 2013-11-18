#include "ping.h"
//Include for signals
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "writer.h"
#include <unistd.h>

pid_t friendPid = 0;

//SIGNAL HANDLERS
void my_handler_int_ping(int s)
{
    printf("Ping : Caught SIGINT\n");
    exit(1);
}

void my_handler_usr_ping(int s)
{
    printf("Ping : I just got ponged, cpt is %i\n", a_read());
    a_write((a_read())+1); //cpt incrementation
    sleep(1);
    kill(friendPid, SIGUSR1);
}

//PING
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
    sigUsrHandler.sa_flags = 0;
    sigaction(SIGUSR1, &sigUsrHandler, NULL);

    //Sending first signal
    a_write(1);
    kill(friendPid, SIGUSR1);
    //Infinite loop
    for (;;)
    {
        /* code */
    }

}