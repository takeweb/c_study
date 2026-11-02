#include <stdlib.h>

#define BUFSIZE 100000000
#define MAX 100000000

int main()
{
    char *p;
    int i;

    for (i = 0; i < MAX; i++)
    {
        p = (char *)malloc(BUFSIZE);
    }
}