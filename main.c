#include "ping.h"
#include "pong.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>


//SIGNAL HANDLERS
void my_handler_1(int s)
{
    printf("Main : caught SIGINT, going to kill myself\n");
}

void my_handler_usr_main(int s)
{
    printf("I just received SIGUSR1");
}

//MAIN
int main(int argc, char const *argv[])
{
    //SIGUSR1 handler (to avoid interruption)
    struct sigaction sigUsrHandler;
    sigUsrHandler.sa_handler = my_handler_usr_main;
    sigemptyset(&sigUsrHandler.sa_mask);
    sigUsrHandler.sa_flags = 0;
    sigaction(SIGUSR1, &sigUsrHandler, NULL);


    //SIGINT handler configuration
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = my_handler_1;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);

    //Child processes launch
    pid_t pid_ping;
    pid_t pid_pong;

    if ((pid_ping = fork()) == 0)
    {
        ping(getppid());
    }
    else
    {
        pong(pid_ping);
        //Waiting for child processes
        waitpid(pid_pong, NULL, 0);
        waitpid(pid_ping, NULL, 0);
    }

    return 0;
}