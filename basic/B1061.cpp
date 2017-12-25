#include <iostream>

using namespace std;

void solution() {

	int N,M;
	cin>>N>>M;

	// 输入题目总分
	int points[M];
	for (int i = 0; i < M; ++i)
		cin>>points[i];
	// 输入正确答案
	int answers[M];
	for (int i = 0; i < M; ++i)
		cin>>answers[i];

	int students[N];
    fill(students, students + N, 0);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int answer;
			cin>>answer;
			if (answer == answers[j])
				students[i] += points[j];
		}
	}

	// 输出部分
	for (int i = 0; i < N; ++i)
		cout<<students[i]<<endl;

}

int main() {
	solution();
	return 0;
}