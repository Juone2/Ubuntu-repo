#include <stdio.h>
#include <sys/types.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int x, y, result = 0;
	int plus = 0;
	int sum = 0;
	printf("insert number..");
	scanf("%d %d", &x , &y);

	pid_t pid;
	int status;

	pid = fork();

	if (pid > 0) {
		printf("parent process..\n");
		result = pow(x, y);
		wait(&status);
		sum = (status >> 8) + result;
		printf("parent: status is %d\n", sum );

	}
	else if (pid == 0) {
		sleep(1);
		printf("child: bye!\n");
		plus = x + y;
		exit(plus);
		
	}
	else printf("fail to fork\n");
	printf("bye!");
}
