#include <iostream>

using namespace std;

void solution(){

    int size;
    cin>>size;

    // wholeDis表示一圈总长度，dis[i]表示从0到i的距离
    int wholeDis = 0;
    int dis[size];
    int temp = 0;
    dis[0] = 0;
    for(int i = 1; i <= size; i++){
        int d;
        cin>>d;
        dis[i] = temp + d;
        wholeDis += d;
        temp += d;
    }

    int lines;
    cin>>lines;

    for(int i = 0; i < lines; i++){
        int from, to;
        cin>>from>>to;
        if(from < to){
            long int x = dis[to - 1] - dis[from - 1];
            cout<<min(x, wholeDis - x)<<endl;
        } else {
            long int x = dis[from - 1] - dis[to - 1];
            cout<<min(x, wholeDis - x)<<endl;
        }
    }

}

int main() {
    /**
    * 测试用例：
    * 5 1 2 4 14 9 3 1 3 2 5 4 1
    * 期待结果：
    * 3 10 7
    */
    solution();
    return 0;
}