#include <iostream>
#include <stack>
#include <iomanip>

using namespace std;

void _solution(int a, int b){

	bool positive = true;
	int sum = a + b;

	if(sum < 0){
		positive = false;
		sum = -sum;
	}

	// 计算和的位数
	int count = 0;
	int sumCopy = sum;
	while(sumCopy != 0){
		sumCopy /= 10;
		count++;
	}

	// 将三个数字作为一组依次入栈
	stack<int> p;
	while(sum >= 1000){
		p.push(sum - (sum / 1000 * 1000));
		sum /= 1000;
	}
	p.push(sum);

	for(int i = 0; !p.empty(); i++){
		// 如果是负数输出一个负号
		if(!positive && i == 0){
			cout<<"-";
		}
		// 如果第一个则直接输出，非第一个则输出一个逗号
		if(i == 0){
			cout<<p.top();
			p.pop();
		} else {
			cout<<",";
			cout<<setw(3)<<setfill('0')<<p.top();
			p.pop();
		}
	}
	cout<<endl;

}

void solution(){
	int x, y;
	cin>>x>>y;
	_solution(x, y);
}

int test(int x, int y) {
    cout<<x<<" + "<<y<<" = ";
    _solution(x, y);
    return 0;
}

int main() {
    test(-100000, 87);
    test(1000, 87);
    test(3000, -87);
    return 0;
}