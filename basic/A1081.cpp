//
// Created by Tom Guo on 16/11/2017.
//

// TODO
// 浮点错误，不知道为啥

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct Fraction {
    LL up, down;
};

Fraction reduction(Fraction result) {

    if (result.down < 0) {
        result.up = -result.up;
        result.down = -result.down;
    }
    if (result.up == 0)
        result.down = 1;
    else {
        LL x = gcd(abs(result.up), abs(result.down));
        result.up /= x;
        result.down /= x;
    }
    return result;
}

Fraction add(Fraction a, Fraction b) {

    a = reduction(a);
    b = reduction(b);

    Fraction result;
    result.up = a.up * b.down + b.up * a.down;
    result.down = a.down * b.down;
    return reduction(result);
}

void printfFraction(Fraction f) {
    if (f.down == 1)
        printf("%lld\n", f.up);
    else if (abs(f.up) > f.down)
        printf("%lld %lld/%lld\n", f.up / f.down, abs(f.up) % f.down, f.down);
    else
        printf("%lld/%lld\n", f.up, f.down);

}
int main() {

//    int size;
//    scanf("%d", &size);
//    Fraction sum, tmp;
//    for (int i = 0; i <size; i++) {
//
//        scanf("%lld/%lld", &tmp.up, &tmp.down);
//
//        tmp = reduction(tmp);
//        sum = add(sum, tmp);
//    }

    printfFraction(sum);


}
