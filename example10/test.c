#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	static struct sigaction act;
	act.sa_handler = int_handle;
	sigfillset(&(act.sa_mask));
	sigaction(SIGINT, &act, NULL);
}

void int_handle(int signum)
{	
	
        printf("file write is end!\n", ++num);
} 
