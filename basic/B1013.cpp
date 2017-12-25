#include <iostream>
#include <cmath>

using namespace std;

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

void solution(){

    int low, high;
    cin>>low>>high;

    int count = 0, i = 2, output = 1;
    while(true) {
        if(isPrime(i)){
            count++;
            if(count >= low){
                if(output % 10 == 1)
                    cout<<i;
                else if(output % 10 == 0)
                    cout<<" "<<i<<endl;
                else
                    cout<<" "<<i;
                output++;
                if(count == high)
                    return;
            }
        }
        i++;
    }

}

int main() {
    /**
     * 测试用例：
     * 5 27
     * 期待结果：
     * 11 13 17 19 23 29 31 37 41 43
     * 47 53 59 61 67 71 73 79 83 89
     * 97 101 103
     */
    solution();
    return 0;
}