#include <stdio.h>

int main()
{
    int x = 1;
    int y = x;
    struct test_t
    {
        int x;
        int y;
    };

    struct test_t t = {1, 2};
    struct test_t s = t;

    printf("x: %d\n", s.x);
    printf("y: %d\n", s.y);

    return 0;
}