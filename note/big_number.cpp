//
// Created by Tom Guo on 17/10/2017.
//

#include <iostream>

using namespace std;

struct bign{
    int d[1000];
    int len;
    bign(){
        memset(d, 0, sizeof(d));
        len = 0;
    }
    friend ostream& operator<<(ostream &os, const bign& bn){
        for(int i = bn.len - 1; i >= 0; i--){
            os<<bn.d[i];
        }
        return os;
    }
};

// 将整数准换为bign
bign change(char str[]){
    bign a;
    a.len = strlen(str);
    for(int i= 0; i <  a.len; i++){
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}

// 比较大小
int compare(bign a, bign b){
    if(a.len > b.len)
        return 1;
    else {
        for(int i = a.len - 1; i>= 0; i--){
            if(a.d[i] > b.d[i])
                return 1;
            else if(a.d[i] < b.d[i])
                return -1;
        }
        return 0;
    }
}


bign add(bign a, bign b){
    bign c;
    int carry = 0;
    for(int i = 0; i < a.len || i < b.len; i++){
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if(carry != 0)
        c.d[c.len++] = carry;
    return c;
}

// 使用前需比较大小
bign substract(bign a, bign b){
    bign c;
    for(int i = 0; i < a.len || i < b.len; i++){
        if(a.d[i] < b.d[i]){
            a.d[i + 1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0)
        c.len--;
    return c;
}

// bign与int型的乘法
bign multiply(bign a, int b){
    bign c;
    int carry = 0;
    for(int i = 0; i < a.len; i++){
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while(carry != 0){
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}

// 除法，未测试
bign divide(bign a, int b, int& mod){
    bign c;
    c.len = a.len;
    for(int i = a.len - 1; i >= 0; i--){
        mod = mod * 10 + a.d[i];
        if(mod < b)
            c.d[i] = 0;
        else {
            c.d[i] = mod / b;
            mod = mod % b;
        }
    }
    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0)
        c.len--;
    return c;
}

int main(){
    char str1[1000], str2[1000];
    int c;
    cin>>str1>>str2>>c;
    bign a = change(str1);
    bign b = change(str2);
    cout<<"a = "<<a<<", b = "<<b<<endl;
    cout<<"a + b = "<<add(a, b)<<endl;
    cout<<"a - b = "<<substract(a, b)<<endl;
    cout<<"a * c = "<<multiply(a, c)<<endl;
}