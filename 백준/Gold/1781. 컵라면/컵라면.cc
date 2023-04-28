#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<long long int, long long int>> v;	//기한, 점수
priority_queue<pair<long long int, long long int>> pq;	//점수, 기한

int date[200009];

int main() {

	int n;
	long long int t, p;
	long long int latest = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t >> p;
		v.push_back({ t, p });
		latest = max(latest, t);
		date[t] = 1;
	}
	sort(v.begin(), v.end());

	int idx = 0;
	for (long long int i = 1; i <= latest; i++) {
		if (date[i] == 0) continue;
		for (int j = idx; j < v.size(); j++) {
			if (v[j].first == i) {
				pq.push({ -v[j].second, -v[j].first});
				idx = j;
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