#include <iostream>
#include <algorithm>
using namespace std;

long long int num[10009];

int main() {

	int n, m;
	long long int sum = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		sum += num[i];
	}
	sort(num, num + n);
	sum /= n;

	int ans = 0;
	long long int start = 1, end = num[n - 1];
	while (start <= end) {
		long long int mid = (start + end) / 2;

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += num[i] / mid;
		}

		if (cnt >= m) {	//mid 가 너무 작다
			start = mid + 1;
			if (ans < mid) ans = mid;
			//cout << "mid: " << mid << " cnt: " << cnt << '\n';
		}
		else if (cnt < m) {	//mid가 너무 크다
			end = mid - 1;
			//cout << "mid: " << mid << " cnt: " << cnt << '\n';
		}
	}

	cout << ans;


	return 0;
}