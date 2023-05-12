#include <iostream>
#include <algorithm>
using namespace std;

int map[303];
int score[303];

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	score[0] = map[0];
	score[1] = map[1] + score[0];
	score[2] = max(map[1], map[0]) + map[2];
	for (int i = 3; i < n; i++) {
		score[i] = max(score[i - 2], score[i - 3] + map[i - 1]) + map[i];
	}

	cout << score[n - 1];

	return 0;
}
