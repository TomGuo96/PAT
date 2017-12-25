//
// Created by Tom Guo on 09/10/2017.
//

#include <iostream>
#include <string>

using namespace std;

int main(){

    string str = "abcd";

    // 使用printf输出string类型
    printf("%s\n", str.c_str());

    // 使用迭代器访问
    for(string::iterator it = str.begin(); it != str.end(); it++)
        cout<<*it<<" ";
    cout<<endl;

    /* length()与size() */

    cout<<"本字符串共有"<<str.length()<<"个字符组成。"<<endl;

    /* insert() */

    str.insert(1, " xyz ");
    cout<<str<<endl;

    string strTemp = "123456";
    str.insert(str.begin() + 3, strTemp.begin(), strTemp.end() - 1);
    cout<<str<<endl;

    /* erase() */

    str.erase(str.begin() + 1);
    cout<<str<<endl;

    str.erase(str.begin() + 2, str.begin() + 4);
    cout<<str<<endl;

    str.erase(5, 2);
    cout<<str<<endl;

    /* substr() */

    cout<<str.substr(2, 3)<<endl;

    /* replace() */

    str.replace(1, 3, "yyyyyyy");
    cout<<str<<endl;

    str.replace(str.begin(), str.end(), "Thank you, Tom. I am glad you are here for me.");
    cout<<str<<endl;

    /* find()和string::npos */

    int pos = 0;
    while(str.find("you", pos) != string::npos){
        int curPos = str.find("you", pos);
        cout<<curPos<<" ";
        pos = curPos + 1;
    }
    cout<<endl;

    /* clear() */

    str.clear();
    cout<<"当前元素个数为："<<str.length()<<endl;
}