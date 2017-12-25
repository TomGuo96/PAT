#include <iostream>
#include <iomanip>

using namespace std;

void solution(){
	
	float arr[1001] = {0};
	float result[2001] = {0};
	
	int size;
	cin>>size;
	
	for(int i = 0; i < size; i++){
		int pos;
		float value;
		cin>>pos>>value;
		arr[pos] += value;
	}
	
	cin>>size;
	for(int i = 0; i < size; i++){
		
		int pos;
		float value;
		cin>>pos>>value;
		
		for(int j = 0; j <= 1001; j++){
			result[pos + j] += arr[j] * value;
		}
	}
	
	int count = 0;
	for(int i = 0; i < 2001; i++){
		if(result[i] != 0){
			count++;
		}
	}
	cout<<count;
	
	for(int i = 2000; i >= 0; i--){
		if(result[i] != 0){
			cout<<" "<<i<<" "<<fixed<<setprecision(1)<<result[i];
		}
	}
	cout<<endl;
	
}

int main() {
	/**
	 * case: 2 1 2.4 0 3.2 2 2 1.5 1 0.5
	 * result: 3 3 3.6 2 6.0 1 1.6
	 */
	solution();
	return 0;
}