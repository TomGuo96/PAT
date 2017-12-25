#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool isPalindromic(string s){
	string str = s;
	reverse(str.begin(), str.end());
	return s == str;
}

void reverseAndAdd(string &str){
	string origin = str;
	reverse(str.begin(), str.end());
	int carry = 0;
	for(int i = (int)origin.length() - 1; i >= 0; i--){
		char sum = str[i] + origin[i] + carry - '0';
		if(sum > '9'){
			carry = 1;
			str[i] = sum - 10;
		} else {
			carry = 0;
			str[i] = sum;
		}
	}
	if(carry != 0){
		str = "1" + str;
	}
}

void solution(){
	
    string num;
    int step;
    cin>>num>>step;

    if(isPalindromic(num)){
        cout<<num<<endl;
        cout<<"0"<<endl;
        return;
    }

    for(int i = 1; i <= step; i++){
        reverseAndAdd(num);
        if(isPalindromic(num)){
            cout<<num<<endl;
            cout<<i<<endl;
            return;
        }
    }
    cout<<num<<endl;
    cout<<step<<endl;

}

int main() {
	/**
	 * 测试用例：
	 * 67 3
	 * 期待结果：
	 * 484 2
	 *
	 * 测试用例：
	 * 69 3
	 * 期待结果：
	 * 1353 3
	 */
	solution();
	return 0;
}

/**
 * 使用字符数组，操作复杂
 */
/*
bool isPalindrmoic(int arr[], int size){

	for(int i = 0; i < size / 2; i++){
		if(arr[i] != arr[size - i - 1])
			return false;
	}
	return true;

}
int* doubleNum(int arr[], int &size){

	int temp[size];
	for(int i = 0; i < size; i++){
		temp[i] = arr[size - i - 1];
	}

	int carry = 0;
	for(int i = size - 1; i >= 0; i--){
		int sum = arr[i] + temp[i] + carry;
		if(sum >= 10){
			carry = sum / 10;
			arr[i] = sum - carry * 10;
		} else {
			arr[i] = sum;
			carry = 0;
		}
	}

	if(carry != 0){
		int* ret = new int[size + 1];
		for(int i = 1; i <= size; i++){
			ret[i] = arr[i - 1];
		}
		ret[0] = carry;
		size += 1;
		return ret;
	}
	return arr;
}
void output(int arr[], int size){
	for(int i = 0; i < size; i++){
		cout<<arr[i];
	}
	cout<<endl;
}
void A1024(){

	char arr[11];
	int step;
	cin>>arr>>step;

	int *num = new int[11];
	int size = (int)strlen(arr);
	for(int i = 0; i < size; i++){
	 num[i] = (int)arr[i] - 48;
	}

	if(isPalindrmoic(num, size)){
		output(num, size);
		cout<<"0"<<endl;
		return 0;
	}

	for(int i = 1; i <= step; i++){
	 num = doubleNum(num, size);
	 if(isPalindrmoic(num, size)){
		 output(num, size);
		 cout<<i<<endl;
		 return 0;
	 }
	}
	output(num, size);
	cout<<step<<endl;
}
 */