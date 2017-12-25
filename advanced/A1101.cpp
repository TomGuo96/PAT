#include <iostream>
#include <set>

using namespace std;

void solution(){

    int size;
    cin>>size;
    int num[size];
    int leftMax[size];
    set<int> st;

    for (int i = 0; i < size; i++) {
        cin>>num[i];
        if(i == 0)
            leftMax[i] = num[i];
        else
            leftMax[i] = max(leftMax[i - 1], num[i]);
    }

    int count = 0;
    int rightMin = num[size - 1];
    for (int i = size - 1; i >= 0; i--) {
        rightMin = min(num[i], rightMin);
        if(num[i] >= leftMax[i] && num[i] <= rightMin){
            count++;
            st.insert(num[i]);
        }
    }

    cout<<count<<endl;
    for(set<int>::iterator it = st.begin(); it != st.end(); it++){
        if(it == st.begin())
            cout<<*it;
        else
            cout<<" "<<*it;
    }
    cout<<endl;

}

int main() {
    /**
     * 测试用例：
     * 5 1 3 2 4 5
     * 期待结果：
     * 3
     * 1 4 5
     */
    solution();
    return 0;
}