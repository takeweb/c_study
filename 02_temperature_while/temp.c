#include <stdio.h>

/* 
  fhr=0,20,・・・,300に対して、
  華氏-摂氏対応表を印字する
*/
int main() {
    float celsius;    /* 摂氏 */
    int lower = 0;    /* 温度表の下限 */
    int upper = 300;  /* 温度表の上限 */
    int step = 20;    /* 温度表の刻み */
    int fahrenheit = lower; /* 華氏 */

    while (fahrenheit <= upper) {
        celsius = 5 * (fahrenheit - 32) / 9;
        printf("%3d %6.1f\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }
}
