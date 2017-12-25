#include <iostream>

using namespace std;

void solution(){

    int size;
    cin>>size;

    int alreadyUse[10001] = {0};

    int lottery[size];
    for(int i = 0; i < size; i++){
        cin>>lottery[i];
        alreadyUse[lottery[i]]++;
    }

    for(int i = 0; i < size; i++){
        if(alreadyUse[lottery[i]] == 1){
            cout<<lottery[i]<<endl;
            return;
        }
    }
    cout<<"None"<<endl;

}

int main() {
    /**
     * 测试用例：
     * 7 5 31 5 88 67 88 17
     * 期待结果：
     * 31
     *
     * 测试用例：
     * 5 888 666 666 888 888
     * 期待结果：
     * None
     */
    solution();
    return 0;
}