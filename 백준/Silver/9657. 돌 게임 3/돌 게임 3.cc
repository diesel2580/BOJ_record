#include <iostream>
using namespace std;

int dp[1001];

int main() {

	int a;
	cin >> a;
	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;
	for (int i = 5; i < 1001; i++) {
		if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0) dp[i] = 1;
	}
	if (dp[a] == 0) cout << "CY";
	else cout << "SK";

	return 0;
}