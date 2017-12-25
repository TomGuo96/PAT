#include <iostream>

using namespace std;

void solution(){

    int times[10] = {0};
    for(int i = 0; i < 10; i++)
        cin>>times[i];

    for(int i = 1; i < 10; i++){
        if(times[i] > 0){
            times[i]--;
            cout<<i;
            break;
        }
    }
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < times[i]; j++)
            cout<<i;
    cout<<endl;

}

int main() {
    /**
     * case: 2 2 0 0 0 3 0 0 1 0
     * result: 10015558
     */
    solution();
    return 0;
}