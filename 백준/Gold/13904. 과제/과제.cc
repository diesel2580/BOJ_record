#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

vector<pair<int, int>> V;	//기한, 점수
priority_queue<pair<int, int>> pq;	//-점수, -기한 (낮은순, 촉박한순) ???? 기한은 어떻게 정렬되어야하는지...

int main() {

	int n;
	int lastdate = -1;
	cin >> n;
	V.push_back({ -1, -1 });
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		lastdate = max(lastdate, a);
		V.push_back({ a, b });
	}
	sort(V.begin(), V.end());

	for (int i = 1; i <= lastdate; i++) {	//날짜
		for (int j = 1; j <= n; j++) {
			if (V[j].first == i) {
				pq.push({ -V[j].second, -V[j].first });	//점수 낮은 순, 기한 촉박한 순
			}
		}
		while (pq.size() > i) {
			pq.pop();
		}
	}

	int sum = 0;
	while (!pq.empty()) {
		int date = -pq.top().second, score = -pq.top().first;
		pq.pop();
		sum += score;
	}
	cout << sum;

	return 0;
}

