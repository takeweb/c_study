#include <stdio.h>

#define LOWER   0   /* 表の下限 */
#define UPPER   300 /* 表の上限 */
#define STEP    20  /* ステップサイズ */

/* 
  1.4 記号定数
  fhr=0,20,・・・,300に対して、
  華氏-摂氏対応表を印字する
*/
int main(void) {
    printf("<<華氏-摂氏対応表>>\n");
    for (int fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        float celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3d %6.1f\n", fahr, celsius);
    }
}
