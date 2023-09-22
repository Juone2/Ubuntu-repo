#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int filedes;
	mode_t oldmask;

	oldmask = umask(023);
	filedes = open("test3.txt", O_CREAT, 0777);
	close(filedes);
}

