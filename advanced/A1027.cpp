#include <iostream>

using namespace std;

void convertToMars(int num, int &m, int &n){
	n = num % 13;
	m = (num - n) / 13;
}

void outputInMars(int num){
	if(num < 10){
		cout<<num;
	} else if(num == 10){
		cout<<"A";
	} else if(num == 11){
		cout<<"B";
	} else {
		cout<<"C";
	}
}

void solution(){
	
	int color[3];
	for(int i = 0; i < 3; i++){
		cin>>color[i];
	}
	
	cout<<"#";
	for(int i = 0; i < 3; i++){
		
		int m, n;
		convertToMars(color[i], m, n);
		outputInMars(m);
		outputInMars(n);
		
	}
	cout<<endl;
	
}

int main() {
	/**
	 * case: 15 43 71
	 * result: #123456
	 */
	solution();
	return 0;
}