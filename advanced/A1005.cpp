#include <iostream>
#include <stack>

using namespace std;

void output(int num){
	switch (num) {
		case 1:
			cout<<"one";
			break;
		case 2:
			cout<<"two";
			break;
		case 3:
			cout<<"three";
			break;
		case 4:
			cout<<"four";
			break;
		case 5:
			cout<<"five";
			break;
		case 6:
			cout<<"six";
			break;
		case 7:
			cout<<"seven";
			break;
		case 8:
			cout<<"eight";
			break;
		case 9:
			cout<<"nine";
			break;
		default:
			cout<<"zero";
			break;
	}
}

void solution(){
	
	char number[100];
	cin>>number;
	
	// 得到各位数字之和
	int len = (int)strlen(number);
	int sum = 0;
	for(int i = 0; i < len; i++){
		sum += (int)number[i] - 48;
	}
	
	if(sum == 0) {
		cout<<"zero"<<endl;
		return;
	}
	
	// 将加和的各个位置上的数字依次入栈
	stack<int> s;
	while(sum > 0){
		s.push(sum - sum / 10 * 10);
		sum /= 10;
	}
	
	if(s.size() == 1){
		output(s.top());
		cout<<endl;
		return;
	} else {
		while(s.size() != 1){
			output(s.top());
			cout<<" ";
			s.pop();
		}
		output(s.top());
		cout<<endl;
		return;
	}
	
}

int main() {
	/**
	 * case: 12345
	 * result: one five
	 */
	solution();
	return 0;
}

/**
 * 使用long int类型，不能处理大数据
 */
/*
// 根据输入的数字输出对应的英文单词
void output(long int num){
	switch (num) {
		case 1:
			cout<<"one";
			break;
		case 2:
			cout<<"two";
			break;
		case 3:
			cout<<"three";
			break;
		case 4:
			cout<<"four";
			break;
		case 5:
			cout<<"five";
			break;
		case 6:
			cout<<"six";
			break;
		case 7:
			cout<<"seven";
			break;
		case 8:
			cout<<"eight";
			break;
		case 9:
			cout<<"nine";
			break;
		default:
			cout<<"zero";
			break;
	}
}
void test1005(){

	long int num;
	cin>>num;

	if(num == 0){
		cout<<"zero"<<endl;
		return;
	}

	// 求出各个位置数字的加和
	long int numCopy = num;
	long int sum = 0;
	while(numCopy != 0){
		sum += numCopy - numCopy / 10 * 10;
		numCopy /= 10;
	}

	// 将加和的各个位置上的数字依次入栈
	stack<long int> s;
	while(sum > 0){
		s.push(sum - sum / 10 * 10);
		sum /= 10;
	}

	if(s.size() == 1){
		output(s.top());
		cout<<endl;
		return;
	} else {
		while(s.size() != 1){
			output(s.top());
			cout<<" ";
			s.pop();
		}
		output(s.top());
		cout<<endl;
		return;
	}

}
*/
