#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void int_handle(int signum);

int num = 0;

int main(void)
{
	static struct sigaction act;
	act.sa_handler = int_handle;
	sigfillset(&(act.sa_mask));
	sigaction(SIGINT, &act, NULL);

	while(1)
	{
		printf("i'm sleepy..\n");
		sleep(1);
		if(num >= 3) exit(0);
	}

	
}

void int_handle(int signum)
{	
	{
		FILE *fp;
		fp = fopen("a.txt", "at");
		printf("SIGINT:%d \n", signum);
		fprintf(fp, "SIGINT: %d \n"), signum);
		printf("int_handle called %d times \n", ++num);
		fprintf(fp, "int_handle called %d times \n", num);
	}
	fclose(fp);
} 
