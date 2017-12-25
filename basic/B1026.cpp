//
// Created by Tom Guo on 15/11/2017.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int solution() {

    int c1, c2;
    cin>>c1>>c2;

    int time = round(((double)c2 - (double)c1) / 100);

    int hours = time / (60 * 60);
    time -= hours * (60 * 60);

    int minutes = time / 60;
    time -= minutes * 60;

    int seconds = time;

    cout.fill('0');
    cout<<setw(2)<<hours<<":"<<setw(2)<<minutes<<":"<<setw(2)<<seconds<<endl;

}

int main() {
    /*
     * case: 2 2 0 0 0 3 0 0 1 0
     * result: 10015558
     */
    solution();
    return 0;
}