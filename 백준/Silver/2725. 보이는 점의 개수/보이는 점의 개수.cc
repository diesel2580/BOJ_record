#include <iostream>
using namespace std;

int num[1003];

int GCD(int a, int b) {	//최대공약수
	if (b == 0) return a;
	else return GCD(b, a % b);
}

void count() {

	num[1] = 3;
	for (int i = 2; i <= 1000; i++) {
		int cnt = 0;
		for (int j = 1; j < i; j++) {
			if (GCD(i, j) == 1) cnt++;
		}
		num[i] = num[i - 1] + cnt * 2;
	}

}

int main() {

	count();
	int test;
	cin >> test;
	for (int T = 0; T < test; T++) {
		int n;
		cin >> n;
		cout << num[n] << '\n';
	}

	return 0;
}
