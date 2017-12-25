//
// Created by Tom Guo on 06/10/2017.
//

#include <cstdio>

int main(){

    /* sscanf的使用 */

    int m;
    char str1[100] = "123";
    sscanf(str1, "%d", &m);
    printf("%d\n", m);

    int m1;
    double m2;
    char m3[100] = "2048:3.14,hello", m4[100];
    sscanf(m3, "%d:%lf,%s", &m1, &m2, m4);
    printf("m1=%d, m2=%.2f, m4=%s\n", m1, m2, m4);

    /* sprintf的使用 */

    int n = 233;
    char str2[100];
    sprintf(str2, "%d", n);
    printf("%s\n", str2);

    int n1 = 12;
    double n2 = 3.1413;
    char strN1[100], strN2[100] = "good";
    sprintf(strN1, "%d:%.2f,%s", n1, n2, strN2);
    printf("%s\n", strN1);
    
    return 0;

}