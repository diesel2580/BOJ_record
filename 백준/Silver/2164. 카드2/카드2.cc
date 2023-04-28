#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main() {

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	int ans = 0;
	while (q.size() > 0) {
		if (!q.empty()) {
			ans = q.front();
			q.pop();
		}
		if (!q.empty()) {
			ans = q.front();
			q.pop();
			q.push(ans);
		}
		
	}

	cout << ans;

	return 0;
}