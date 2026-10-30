#include <stdio.h>
#include <math.h>

/*
  演習1-4
  摂氏-華氏対応表を印字する
*/
int main(void) {
    for (int i = 0; i <= 15; i++) {
        float celsius = (-160.0 + 100.0 * i) / 9.0;
        float fahr = (9.0 / 5.0) * celsius + 32;
        printf("%6.1f %3ld\n", celsius, lround(fahr));
    }
}
