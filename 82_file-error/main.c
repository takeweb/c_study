#include <stdio.h>

#define BUFSIZE 1024

int main()
{
    FILE *fp;
    char buf[BUFSIZE];
    int read_size;

    fp = fopen("test.txt", "r");
    read_size = fread(buf, 1, BUFSIZE, fp);
    printf("read size: %d\n", read_size);
    fclose(fp);

    return 0;
}