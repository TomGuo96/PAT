#include <iostream>
#include <iomanip>

using namespace std;

void solution(){
	
	float arr[1001] = {0};
	
	for(int i = 0; i < 2; i++){
		int size;
		cin>>size;
		for(int i = 0; i < size; i++){
			int x;
			float y;
			cin>>x>>y;
			arr[x] += y;
		}
	}
	
	// 计算加和并计算非零项的个数
	int count = 0;
	for(int i = 0; i <= 1000; i++){
		if(arr[i] != 0)
			count++;
	}
	
	cout<<count;
	for(int i = 1000; i >= 0; i--){
		// 输出系数非零项，并控制输出精度为0.1
		if(arr[i] != 0)
		 cout<<" "<<i<<" "<<fixed<<setprecision(1)<<arr[i];
	}
	cout<<endl;
	
}

int main() {
	/**
	 * case1: 4 1 1.5 2 2.4 3 10 20 0.77 3 20 -0.77 5 5.1234 100 2
	 * case2: 1 1 1 1 1 -1
	 */
	solution();
	return 0;
}