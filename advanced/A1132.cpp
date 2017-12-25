#include <iostream>

using namespace std;

void _solution(int num){
	
	// 求出数字总位数count
	int sumCopy = num;
	int count = 0;
	while(sumCopy != 0){
		sumCopy /= 10;
		count++;
	}
	
	if(count % 2 == 1)
		return;
	// 求出基数n
	int n = 1;
	for(int i = 0; i < count / 2; i++){
		n *= 10;
	}
	
	// 求出左右两部分数字
	int left = num / n;
	int right = num - left * n;
	
	// 处理156000这种情况
	if(left == 0 || right == 0){
		cout<<"No"<<endl;
		return;
	}
	
	if(num % (left * right) == 0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	
}
void solution(){
	
	int line;
	cin>>line;

	for(int i = 0; i < line; i++){
		int num;
		cin>>num;
		_solution(num);
	}
	
}

int main() {
	/**
	 * 测试用例：
	 * 3 167334 2333 12345678
	 * 期待结果：
	 * Yes
	 * No
	 * No
	 */
    solution();
    return 0;
}