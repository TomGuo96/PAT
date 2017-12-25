#include <iostream>
#include <cmath>

using namespace std;

// 判断一个数是否为质数
bool isPrime(int num){
	
	if(num <= 1)
		return false;
	
	for(int i = 2; i <= sqrt(num); i++){
		if(num % i == 0)
			return false;
	}
	return true;
	
}

// 在radix进制下反转数字
int reverseWithRadix(int num, int radix){
	int temp = num;
	num = 0;
	while(temp > 0) {
		int mod = temp % radix;
		if (num == 0) {
			num += mod;
		} else {
			num *= radix;
			num += mod;
		}
		temp = (temp - mod) / radix;
	}
	return num;
}

void solution(){
	
	while(true){
		
		int num;
		cin>>num;
		
		if (num > 0) {
			
			int radix;
			cin>>radix;
			int reverse = reverseWithRadix(num, radix);
			
			if(isPrime(num) && isPrime(reverse))
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
			
		} else
            return;
		
	}
	
}

int main() {
	/**
	 * case: 73 10 23 2 23 10 -2
	 * result: Yes Yes No
	 */
	solution();
	return 0;
}