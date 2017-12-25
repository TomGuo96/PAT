//
// Created by Tom Guo on 17/10/2017.
//

#include <iostream>
#include <queue>

using namespace std;

/*******
 * 未测试
 *******/

const int maxn = 100;

struct node{
    int x, y;
} Node;

int n, m;
int matrix[maxn][maxn];
// 记录是否入过队
bool inq[maxn][maxn] = {false};
// 增量数组
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

bool judge(int x, int y){
    if(x >= n || x < 0 || y >=m || y < 0)
        return false;
    if(matrix[x][y] == 0 || inq[x][y])
        return false;
    return true;
}

// 访问(x, y)所在的块，将所在的块中的1的inq都设置为true
void BFS(int x, int y){
    queue<node> Q;
    Node.x = x;
    Node.y = y;
    Q.push(Node);
    inq[x][y] = true;
    while(!Q.empty()){
        node top = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++){
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(judge(newX, newY)){
                Node.x = newX;
                Node.y = newY;
                Q.push(Node);
                inq[newX][newY] = true;
            }
        }

    }
}

int main(){

    int m, n;
    cin>>m>>n;

    // 输入数组
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            cin>>matrix[x][y];
        }
    }

    int ans = 0;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            if(matrix[x][y] == 1 && !inq[x][y]){
                ans++;
                BFS(x, y);
            }
        }
    }
}