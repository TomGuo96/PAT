#include <iostream>

using namespace std;

// 初始化牌组为整数列
void initCards(int cards[]){
    for(int i = 0; i < 54; i++)
        cards[i] = i + 1;
}
// 根据数字输出对应的牌面
void outputCard(int card){

    if(card <= 13)
        cout<<"S"<<card;
    else if(card <= 26)
        cout<<"H"<<card - 13;
    else if(card <= 39)
        cout<<"C"<<card - 26;
    else if(card <= 52)
        cout<<"D"<<card - 39;
    else
        cout<<"J"<<card - 52;

}
// 按格式输出牌组
void outputCards(int cards[]){
    outputCard(cards[0]);
    for(int i = 1; i < 54; i++){
        cout<<" ";
        outputCard(cards[i]);
    }
    cout<<endl;
}

// 按照shu的顺序洗一次牌
void shuffle(int cards[], int shu[]){
    int temp[54];
    for(int i = 0; i < 54; i++)
        temp[i] = cards[i];
    for(int i = 0; i < 54; i++){
        cards[shu[i] - 1] = temp[i];
    }
}

void solution(){

    int times;
    int shu[54];
    cin>>times;
    for(int i = 0; i < 54; i++)
        cin>>shu[i];

    int cards[54];
    initCards(cards);

    for(int i = 0; i < times; i++)
        shuffle(cards, shu);

    outputCards(cards);

}

int main() {
    /**
     * 测试用例：
     * 2 36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
     * 期待结果：
     * S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 D2 D3 D4 H6 H3 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5
     */
    solution();
    return 0;
}