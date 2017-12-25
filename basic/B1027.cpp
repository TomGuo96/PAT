#include <iostream>

using namespace std;

int max(int sum, int& left) {

	int cur = 3;
	left = sum - 1;
	while (left - cur * 2 >= 0) {
		left -= cur * 2;
		cur += 2;
	}
	return cur - 2;

}

void solution() {
	
	int sum;
	char ch;
	cin>>sum>>ch;

	int left;
	int m = max(sum, left);
	int cur = m;
	while (cur > 0) {
		int i;
		for (i = 0; i < (m - cur) / 2; ++i)
			cout<<" ";	
		for (i = 0; i < cur; ++i)
			cout<<ch;
		cout<<endl;
		cur -= 2;
	}
	cur += 4;
	while (cur <= m) {
		int i;
		for (i = 0; i < (m - cur) / 2; ++i)
			cout<<" ";	
		for (i = 0; i < cur; ++i)
			cout<<ch;
		cout<<endl;
		cur += 2;
	}
	cout<<left<<endl;

}

int main() {
	solution();
	return 0;
}