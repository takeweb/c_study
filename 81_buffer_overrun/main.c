#include <stdio.h>
#define BUFSIZE 1024

int main()
{
    int ibuf[BUFSIZE];
    int i;

    for (i = 0; i < BUFSIZE + 2; i++)
    {
        ibuf[i] = i;
    }
    return 0;
}