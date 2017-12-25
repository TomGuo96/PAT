#include<iostream>

using namespace std;

void solution() {
    int number;
    cin>>number;

    int step = 0;
    while(number != 1){
        number = (number % 2 == 0) ? number / 2 : ((3 * number) + 1) / 2;
        step++;
    }

    cout<<step<<endl;
    return;
}

int main() {
    /**
     * case: 3
     * result: 5
     */
    solution();
    return 0;
}