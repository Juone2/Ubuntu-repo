#include <sys/time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSIZE 11

void parent(int [][]);
int child(int []);

pid_t pid;
int i;

void onerror(char *msg) 
{
	printf("%s");
	exit(1);
}	

int main() {

for (i = 0; i < 3; i++) {
	pid = fork();
	if (pid < 0) {
		fprintf(stderr, "fork failed\n");
		return 1;
	} else if (pid == 0) {
			printf("child Process Id: %d, Parent Process Id: %d\n", getpid(), getppid())			exit(0);
		}
	}
	
}i
