#include <stdio.h>

#define BUFSIZE 1024

int main()
{
    FILE *fp;
    char buf[BUFSIZE];
    int read_size;
    int ret_val;

    fp = fopen("test.txt", "r");
    if (fp != NULL)
    {
        read_size = fread(buf, 1, BUFSIZE, fp);
        fclose(fp);
        printf("read size: %d\n", read_size);
        ret_val = 0;
    }
    else
    {
        fprintf(stderr, "Failed to open the file");
        ret_val = 1;
    }

    return ret_val;
}