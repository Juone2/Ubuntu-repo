#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int i;
	int num;
	int mult = 1;
	int sum = 0;

	printf("please enter int number\n");
	scanf("%d", &num);

	if (num <=  0) 
	{
		printf("양의 정수가 아닙니다.\n");
	}
	
	pid = fork();

	if (pid > 0)
	{
		for(i = 1; i <= num; i++) 
		{
			sum += i;
		}
		printf("sum : %d\n", sum);
	}
	else if (pid == 0)
	{
		for (i = 1; i <= num; i++)
		{
			mult *= i;
		}
		printf("mult : %d\n", mult);
	}
	else 
	{
		printf("fork failed\n");
	}
}
