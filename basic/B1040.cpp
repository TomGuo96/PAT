#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

void solution(){

    string str;
    cin>>str;

    int len = str.length();

    int leftP[len], rightT = 0;
    fill(leftP, leftP + len, 0);

    for(int i = 1; i < len; i++){
        if(str[i - 1] == 'P')
            leftP[i] = leftP[i - 1] + 1;
        else
            leftP[i] = leftP[i - 1];
    }

    int ans = 0;
    for(int i = len - 2; i >= 0; i--){
        if(str[i + 1] == 'T')
            rightT++;
        if(str[i] == 'A')
            ans = (ans + leftP[i] * rightT) % MOD;
    }
    cout<<ans<<endl;

}

int main() {
    /*
     * case: APPAPT
     * result: 2
     */
    solution();
    return 0;
}