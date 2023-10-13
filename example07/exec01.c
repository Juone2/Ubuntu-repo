#include <unistd.h>

int main() 
{
  execlp("ls", "ls", "-l", "exmaple07", (char *)0);
}
