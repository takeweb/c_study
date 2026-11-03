#include <stdio.h>

/* 
  演習1-5
  fhr=0,20,・・・,300に対して、
  華氏-摂氏対応表を逆順に印字する
*/
int main(void) {
    printf("<<華氏-摂氏対応表>>\n");
    for (int fahr = 300; fahr >= 0; fahr -= 20) {
        float celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3d %6.1f\n", fahr, celsius);
    }
}
