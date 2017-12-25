#include <iostream>

using namespace std;

void solution(){

    int x, y, sum, radix = 0;
    cin>>x>>y>>radix;
    sum = x + y;

    int arr[31];
    int i = 0;

    // 注意0+0的情况
    do {
        arr[i++] = sum % radix;
        sum /= radix;
    } while(sum > 0);

    for(int j = i - 1; j >= 0; j--)
        cout<<arr[j];
    cout<<endl;

}

int main() {
    /**
     * case: 123 456 8
     * result: 1103
     */
    solution();
    return 0;
}