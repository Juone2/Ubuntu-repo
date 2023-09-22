#include <stdio.h>
#include <stdlib.h>
#inlcude <unistd.h>

int main(int argc, char **argv) 
{
	char *filename = "test4.txt";

	if ( access(argv[1], R_OK) == -1) 
	{
		fprintf( stderr, "User cannot read file %s\n", argv[1]);
		exit(1);
	}
	printf("%s readable, proceeding \n", argv[1]);
}
