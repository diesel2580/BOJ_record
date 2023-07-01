#include <iostream>
using namespace std;

int num[10009];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		num[tmp]++;
	}
	for (int i = 1; i <= 10000; i++) {
		if (num[i] == 0) continue;
		for (int j = 0; j < num[i]; j++) {
			cout << i << '\n';
		}
	}

	return 0;
}