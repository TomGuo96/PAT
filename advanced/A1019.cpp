#include <iostream>
#include <vector>

using namespace std;

// 输出向量
void output(vector<int> vec){

    for(int i = vec.size() - 1; i >= 0; i--){
        if(i == vec.size() - 1){
            cout<<vec[i];
        } else {
            cout << " " << vec[i];
        }
    }
    cout<<endl;

}

// 判断一个整数向量是否回文
bool isPalindromic(vector<int> vec){

    for(int i = 0; i < vec.size() / 2; i++){
        if(vec[i] != vec[vec.size() - i - 1])
            return false;
    }
    return true;

}

void _solution(long int num, long int radix){

    vector<int> vec;
    vec.clear();

    if(num == 0){
        vec.push_back(0);
    } else {
        while(num > 0) {
            vec.push_back(num - num / radix * radix);
            num /= radix;
        }
    }

    if(isPalindromic(vec)){
        cout<<"Yes"<<endl;
        output(vec);
    } else {
        cout<<"No"<<endl;
        output(vec);
    }

}

void solution(){
    int num, radix;
    cin>>num>>radix;
    _solution(num, radix);
}

int main() {
    /**
     * case1: 27 2
     * result: Yes 1 1 0 1 1
     * case2: 121 5
     * result: No 4 4 1
     */
    solution();
    return 0;
}