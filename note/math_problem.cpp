//
// Created by Tom Guo on 16/10/2017.
//

#include <iostream>
#include <cmath>

using namespace std;

// 分数
struct Fraction{
    int up, down;
};

// 最大公约数
int gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// 最小公倍数
int lcm(int a, int b){
    return a / gcd(a, b) * b;
}

//分数的化简
Fraction reduction(Fraction result){
    if(result.down < 0){
        result.up = - result.up;
        result.down = - result.down;
    }
    if(result.up == 0)
        result.down = 1;
    else {
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}

// 分数加法
Fraction add(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}

// 分数减法
Fraction minus(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}

// 分数乘法
Fraction multiply(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}

// 分数除法
Fraction divide(Fraction f1, Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}

// 输出分数
void showResult(Fraction r){
    r = reduction(r);
    if(r.down == 1)
        cout<<r.up;
    else if(abs(r.up) > r.down){
        cout<<r.up / r.down<<" "<<abs(r.up) % r.down<<"/"<<r.down;
    } else
        cout<<r.up<<"/"<<r.down;
}

// 判读是否是素数
bool isPrime(int n){
    if(n <= 1)
        return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqr; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}