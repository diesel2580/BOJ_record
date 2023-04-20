#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int, int>> pq;	//-price, -date
vector<pair<int, int>> V;	//date, price

int main() {

	int n;
	int date = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p, d;
		date = max(date, d);
		cin >> p >> d;
		V.push_back({ d, p });
		if (n == 1) {
			cout << p;
			return 0;
		}
	}
	sort(V.begin(), V.end());

	for (int i = 1; i <= date; i++) {
		for (int j = 0; j < n; j++) {
			if (V[j].first == i) {
				pq.push({ -V[j].second, -V[j].first });
			}
		}
		while (pq.size() > i) {
			pq.pop();
		}
	}

	int ans = 0;
	while (!pq.empty()) {
		ans += -pq.top().first;
		pq.pop();
	}

	cout << ans;

	return 0;
}