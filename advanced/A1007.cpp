#include<iostream>

using namespace std;

// 尝试向左拓展子数组
bool tryToLeft(int arr[], int &left){
	int offset = 0;
	int p = left;
	while(p > 0){
		offset += arr[p - 1];
		p--;
		if(offset > 0){
			left = p;
			return true;
		}
	}
	return false;
}

// 尝试向右拓展子数组
bool tryToRight(int arr[], int size, int &right){
	int offset = 0;
	int p = right;
	while(p < size - 1){
		offset += arr[p + 1];
		p++;
		if(offset > 0){
			right = p;
			return true;
		}
	}
	return false;
}

void solution(){
	
	int size;
	cin>>size;
	
	int arr[size];
	for(int i = 0; i < size; i++){
		cin>>arr[i];
	}
	
	int sum = 0;
	int start = 0;
	int end = size - 1;
	
	for(int i = 0; i < size; i++){
		// 学找到一个非负数，作为中心点
		if(arr[i] < 0)
			continue;
		
		int left, right;
		left = right = i;
		int curSum = 0;
		bool success = true;
		
		while(success){
			bool succ1 = tryToLeft(arr, left);
			bool succ2 = tryToRight(arr, size, right);
			if(!succ1 && !succ2){
				success = false;
			}
		}
		
		// 求出当前中心点的最大和
		for(int i = left; i <= right; i++){
			curSum += arr[i];
		}
		// 处理 4 -1 0 -3 0 这种情况
		if(left == right && arr[i] == 0){
			cout<<"0 0 0"<<endl;
			return;
		}
		if(curSum > sum){
			sum = curSum;
			start = left;
			end = right;
		}
	}
	cout<<sum<<" "<<arr[start]<<" "<<arr[end]<<endl;

}

int main() {
	/**
	 * case: 10 -10 1 2 3 4 -5 -23 3 7 -21
	 * result: 10 1 4
	 */
	solution();
}