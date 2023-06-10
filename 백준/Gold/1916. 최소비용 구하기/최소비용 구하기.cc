#pragma warning (disable:4996)
#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define INF 1e9

priority_queue<pair<int, int>> pQ; // -거리, 정점
vector<pair<int, int>> V[1001]; // 정점s, 정점e, 거리
int dist[1001];

int main() {
	int n, m;
	int s, e, d;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &s, &e, &d);
		V[s].push_back({ e, d });
	}
	int start, end;
	scanf("%d %d", &start, &end);

	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	pQ.push({ 0, start });
	dist[start] = 0;

	while (!pQ.empty()) {
		int dnow = -pQ.top().first;
		int now = pQ.top().second;
		pQ.pop();

		if (dist[now] < dnow) {
			continue;
		}

		for (int i = 0; i < V[now].size(); i++) {
			int next = V[now][i].first;		//연결 정점
			int dnext = V[now][i].second;	//거리
			if (dist[next] > dnow + dnext) {
				dist[next] = dnow + dnext;
				pQ.push({ -(dnext + dnow), next});
			}
		}
	}

	

	printf("%d", dist[end]);

	return 0;
}