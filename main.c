#include "ping.h"
#include "pong.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


//SIGINT HANDLER
void my_handler_1(int s)
{
    printf("Main : caught SIGINT, going to kill myself\n");
}

int main(int argc, char const *argv[])
{
    //SIGINT handler configuration
    struct sigaction sigIntHandler;

    sigIntHandler.sa_handler = my_handler_1;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);

    //
    pid_t pid_ping = fork();
    pid_t pid_pong;

    if ((pid_ping = fork()) == 0){
    	if ((pid_pong = fork()) == 0){
    		pong();
    	}
    	ping();
    }
    else{
    	waitpid(pid_pong,NULL,0);
    	waitpid(pid_ping,NULL,0);
    }

    return 0;
}