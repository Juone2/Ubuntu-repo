#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
	pid_t pid;
	int i = 0;

	i++;
	printf("before calling fork(%d)\n", i);

	pid = fork();

	if(pid == 0) 
	{
		/* 자식 프로세스*/
		printf("child process(%d)\n", ++i);
	}
	else if(pid > 0)
	{	
		/* 부모 프로세스*/
		printf("parent process(%d)\n", --i);
	}
	else 
	{
		/* fork 호출 실패*/
		printf("fail to fork\n");
	}
}
