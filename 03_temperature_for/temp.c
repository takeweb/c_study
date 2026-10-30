#include <stdio.h>

/* 
  fhr=0,20,・・・,300に対して、
  華氏-摂氏対応表を印字する
*/
int main(void) {
    // 演習1-3
    printf("<<華氏-摂氏対応表>>\n");
    for (int fahr = 0; fahr <= 300; fahr += 20) {
        float celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3d %6.1f\n", fahr, celsius);
    }
}
