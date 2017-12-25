#include <iostream>
#include <iomanip>

using namespace std;

void solution(){
	
	float arr[3][3];
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cin>>arr[i][j];
	
	float odd = 1;
	for(int i = 0; i < 3; i++){
		float maxOdd = 1;
		int result = 0;
		for(int j = 0; j < 3; j++){
			if(arr[i][j] > maxOdd){
				maxOdd = arr[i][j];
				result = j;
			}
		}
		odd *= maxOdd;
		switch (result) {
			case 0:
				cout<<"W ";
				break;
			case 1:
				cout<<"T ";
				break;
			default:
				cout<<"L ";
				break;
		}
	}
	
	cout<<fixed<<setprecision(2)<<(odd * 0.65 - 1) * 2<<endl;

}

int main() {
	/**
	 * case: 1.1 2.5 1.7 1.2 3.0 1.6 4.1 1.2 1.1
	 * result: T T W 37.98
	 */
	solution();
	return 0;
}