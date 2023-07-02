#include <iostream>
using namespace std;

int cntzero(int n) {
	int cnt = 0;
	if (n == 0) cnt++;
	while (n > 0) {
		if (n % 10 == 0) cnt++;
		n /= 10;
	}
	return cnt;
}

int main() {

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n, m;
		int cnt = 0;
		cin >> n >> m;
		for (int i = n; i <= m; i++) {
			cnt += cntzero(i);
		}
		cout << cnt << '\n';
	}

	return 0;
}