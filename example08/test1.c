#include <stdio.h>
#include <sys/types.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
        int x, y, 
	int result = 0;
        int plus = 0;
        int sum = 0;
	int sumpow = 0;

        printf("insert number..");
        scanf("%d %d", &x , &y);

        pid_t pid1, pid2;
        int status;

	pid1 = pid2 = -1;

        pid1 = fork();
	if(pid1 > 0) pid2 = fork();
	
	/* 부모 프로세스*/
        if (pid1 > 0 && pid2 > 0) {
		result = pow(x, y);
		sumpow = result >> 8;
		waitpid(pid2, &status, 0);
		plus = status >> 8;
		waitpid(pid1, &status, 0);
		sum = status >> 8;
                printf("3 - 2 - 1 = %d\n", plus - sum - result);
        }
	/* 첫 번째 자식 프로세스*/
        else if (pid1 == 0 && pid2 == -1) {
                sleep(1);
                for (int i = x; i <= y; i++) {
			plus += i;
		} 
		printf("child : %d\n", plus);
                exit(plus);

        }
	/* 두 번째 자식 프로세스*/
        else if (pid1 > 0 && pid2 == 0) {
                sleep(2);
                for (int i = x; i <= y; i++) {
			sum *= i;
		}
		printf("child2 : %d\n", sum);
                exit(sum);
	}
        else printf("fail to fork\n");
        printf("bye!");
}
