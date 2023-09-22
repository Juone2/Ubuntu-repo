#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
        int filedes;
        char filename[] = "temp0.txt";

        if((filedes = open(filename, O_CREAT | O_RDWR | O_EXCL,  0644)) == -1)
        {
                printf("file open error!\n");
                exit(1);
	}

	close(filedes);
}
