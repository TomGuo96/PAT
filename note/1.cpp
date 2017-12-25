//
// Created by Tom Guo on 06/10/2017.
//

#include <cstdio>
#include <cmath>

#define PI1 3.14
const double PI2 = 3.1415;

typedef long long LL;

int main(){

    /* 一个简单的C语言程序 */

//    int a, b;
//    scanf("%d%d", &a, &b);
//    printf("%d\n", a + b);


    /* 基本数据类型 */

    // int型的表示范围是-2^31到2^31-1，约为-2*10^9到2*10^9
    int smallNum = 3214;

    // long long型表示范围是-2^63到2^63-1，约为-9*10^18到9*10^18
    long long bigNum = 214748364999LL; // 书上说大于2^31-1的初值，不使用LL会报错，但是测试后没有发现
    printf("%lld\n", bigNum);

    // float型有效精度为6-7位
    float f1 = 3.1415;
    // double型有效精度为15-16位
    double d1 = 3.1415926536;

    // char类型表示范围是-128到127
    char c1 = 'z', c2 = 'j', c3 = 117;
    printf("%c%c%c\n", c1, c2, c3);
    // 转义字符
    printf("%c%c\n%s\n", '\0', '\n', "以上是两个转义字符。");

    // 字符数组
    char str1[25] = "No one loves me.", str2[25] = "It's a sad story"; // char="abcd"为非法语句
    printf("%s\n%s\n", str1, str2);

    // bool型 注意：C语言与包含<cstdbool>来使用
    bool flag1 = 0, flag2 = true;
    printf("%d\t%d\t%d\n", flag1, flag2, flag1 == flag2);

    // 强制类型准换
    double radius = 12.567;
    int divisor = 10, dividend = 3;
    printf("%.2f\n", radius);
    printf("%.9f\n", (double)divisor / dividend);

    // 符号常量和const常量 注意：宏定义可定义语句
    printf("%f\t%f\n", PI1, PI2);

    /* 运算符 */

//    // 无穷大的数INF
//    const int INF1 = (1 << 30) - 1;
//    const int INF2 = 0x3fffffff;

    /* 使用scanf与printf输入与输出 */

//    // 时间型数据的输入
//    int hours, minutes, seconds;
//    scanf("%d:%d:%d", &hours, &minutes, &seconds);
//    printf("%s%d:%d:%d", "现在的时间是： ", hours, minutes, seconds);

//    // 字符与字符串的输入
//    char nullChar, chars[20];
//    scanf("%c%s", &nullChar, chars); // 除字符串外均使用&符号输入
//    printf("[%c][%s]\n", nullChar, chars);

//    // double型的输入与输出
//    double doubleNumber;
//    scanf("%lf", &doubleNumber); // 输入使用%lf，输出使用%f
//    printf("%f\n", doubleNumber);

    // 输出\和%
    printf("\\\t%%\n");

    // %md格式的输出
    printf("%5d\n%5d\n", 123, 123456);

    // %0md格式的输出
    printf("%05d\n%05d\n", 123, 123456);

    // %.mf格式的输出
    double dx = 1.23456;
    printf("%.1f\t%.2f\t%.3f\n", dx, dx, dx); // 四舍五入使用round函数

    /* 使用getchar与putchar输入与输出 */

    // getchar可接受换行符

    /* typedef */

    // 使用typedef定义数据类型的别名

    /* 常用Math函数 */

    // fabs(double x)
    printf("%.2f\n", -12.345);

    // floor(dobule x)和ceil(double x)
    printf("%.0f %.0f\n", floor(3.456), ceil(3.456));

    // pow(double r, double p)
    printf("%.0f\n", pow(2.0, 3.0));

    // sqrt(double x)
    printf("%f\n", sqrt(3.0));

    // log(double x)
    printf("%f\n", log(1.0));

    // sin,cos,tan,asin,acos,atan

    // round(double x)
    printf("%d\n", (int)round(3.56));


}
