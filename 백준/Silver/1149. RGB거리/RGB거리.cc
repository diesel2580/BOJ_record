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

	cin >> r[0] >> g[0] >> b[0];
	for (int i = 1; i < n; i++) {
		cin >> r[i] >> g[i] >> b[i];
		r[i] += min(g[i-1], b[i-1]);
		g[i] += min(r[i - 1], b[i - 1]);
		b[i] += min(g[i - 1], r[i - 1]);
	}
	
	cout << min3(r[n - 1], g[n - 1], b[n - 1]);

	return 0;
}
