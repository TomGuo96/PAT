#include <iostream>
#include <cstring>

using namespace std;

void solution(){

    int size;
    cin>>size;

    int score[size];
    memset(score, 0, sizeof(score));

    for(int i = 0; i < size; i++){

        int id, sc;
        cin>>id>>sc;

        score[id - 1] += sc;

    }

    int maxId = 0;
    for(int i = 0; i < size; i++)
        maxId = score[i] > score[maxId] ? i : maxId;

    cout<<maxId + 1<<" "<<score[maxId]<<endl;
    return;

}

int main() {
    /**
     * 测试用例：
     * 6 3 65 2 80 1 100 2 70 3 40 3 0
     * 期待结果：
     * 2 150
     */
    solution();
    return 0;
}