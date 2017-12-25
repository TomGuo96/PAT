//
// Created by Tom Guo on 10/10/2017.
//

#include <iostream>
#include <utility>
#include <map>

using namespace std;

int main(){

    pair<int, int> p1(5, 10);
    pair<int, int> p2(5, 15);
    pair<int, int> p3(10, 5);

    if(p1 < p3)
        cout<<"p1 < p3\n";
    if(p1 <= p3)
        cout<<"p1 <= p3\n";
    if(p1 > p2)
        cout<<"p1 > p2\n";

    map<string, int> mp;
    mp.insert(make_pair("heihei", 5));
    mp.insert(pair<string ,int>("haha", 10));
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
        cout<<it->first<<" "<<it->second<<endl;

    return 0;
}