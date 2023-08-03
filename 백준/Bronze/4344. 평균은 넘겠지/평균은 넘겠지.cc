#include <iostream>
using namespace std;

int num[1002];

int main() {

	int test;
	cin >> test;
	for (int T = 0; T < test; T++) {
		int n;
		cin >> n;
		float sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
			sum += num[i];
		}
		sum /= (float)n;
		float cnt = 0;
		for (int i = 0; i < n; i++) {
			if (num[i] > sum) cnt++;
		}

		cout << fixed;
		cout.precision(3);
		cout << (cnt / (float)n) * 100 << "%\n";
		//cout << "avg: " << sum << " ans: " << (cnt/(float)n )*100 << "\n\n";
	}

	return 0;
}