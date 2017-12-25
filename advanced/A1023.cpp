#include <iostream>

using namespace std;

void solution() {

	char str[20];
	cin >> str;

	// 看原始数据使用各个数字的次数
	int k = (int) strlen(str);
	int used[10] = {0};
	for (int i = 0; i < k; i++) {
		used[(int(str[i]) - 48)] += 1;
	}

	// 得到原始数据的二倍
	int result[20];
	int more = 0;
	for (int i = k - 1; i >= 0; i--) {
		int num = (int(str[i]) - 48) * 2 + more;
		more = num / 10;
		result[i] = num - more * 10;
	}

	// 测试使用次数是否完全相同
	for (int i = 0; i < k; i++) {
		used[result[i]] -= 1;
	}
	if (more != 0)
		used[more] -= 1;

	// 输出部分
	for (int i = 0; i < 10; i++) {
		if (used[result[i]] != 0) {
			cout << "No" << endl;
			if (more != 0)
				cout << more;
			for (int j = 0; j < k; j++)
				cout << result[j];
			cout << endl;
			return;
		}
	}
	cout << "Yes" << endl;
	if (more != 0)
		cout << more;
	for (int i = 0; i < k; i++)
		cout << result[i];
	cout << endl;
	return;

}

int main() {
	/*
	 * case: 1234567899
	 * result: Yes 2469135798
	 */
	solution();
	return 0;
}