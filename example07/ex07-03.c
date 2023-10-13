#include <unistd.h>
#include <stdio.h>

int main() 
{
  printf("before ls -l\n");
  execl("/bin/ls", "ls", "-l", (char)* 0);
  printf("after ls -l\n");
}
