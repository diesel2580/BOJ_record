#include <iostream>
#include <algorithm>
using namespace std;

int min3(int a, int b, int c) {
	return min(a, min(b, c));
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int r[1002], g[1002], b[1002];
	int dp[1002][3];

	for (int i = 0; i < n; i++) {
		cin >> r[i] >> g[i] >> b[i];
	}
	dp[0][0] = r[0];
	dp[0][1] = g[0];
	dp[0][2] = b[0];

	for (int i = 1; i < n; i++) {
		int m = min3(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);
		if (m == dp[i - 1][0]) {	//r
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r[i];
			dp[i][1] = m + g[i];
			dp[i][2] = m + b[i];
		}
		else if (m == dp[i - 1][1]) {
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g[i];
			dp[i][0] = m + r[i];
			dp[i][2] = m + b[i];
		}
		else if (m == dp[i-1][2]) {
			dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + b[i];
			dp[i][1] = m + g[i];
			dp[i][0] = m + r[i];
		}
		
	}

	cout << min3(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]);

	return 0;
}
