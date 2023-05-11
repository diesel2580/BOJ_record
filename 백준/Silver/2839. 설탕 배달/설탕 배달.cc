#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	int cnt = 0;
	int tmp = n;
	cnt += tmp / 5;
	tmp %= 5;
	while (1) {
		if (tmp == 0) break;
		if (tmp % 3 != 0) {
			cnt--;
			tmp += 5;;
		}
		else {
			cnt += tmp / 3;
			tmp %= 3;
			break;
		}
		if (tmp > n) {
			cnt = -1;
			break;
		}
	}

	cout << cnt;

	return 0;
}