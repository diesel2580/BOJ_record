#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main() {

	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int n;
		cin >> n;
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;

		int visit[303][303] = {0, };
		queue<pair<pair<int, int>, int>> q;

		int ans = 0;
		visit[sx][sy] = 1;
		q.push({ { sx, sy }, 0 });
		while (!q.empty()) {
			int nowx = q.front().first.first, nowy = q.front().first.second;
			int cnt = q.front().second;
			q.pop();
			if (nowx == ex && nowy == ey) {
				ans = cnt;
				break;
			}

			for (int i = 0; i < 8; i++) {
				int nextx = nowx + dx[i], nexty = nowy + dy[i];
				if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= n || visit[nextx][nexty] != 0) continue;
				q.push({ { nextx, nexty }, cnt + 1 });
				visit[nextx][nexty] = 1;
			}
		}
		cout << ans << '\n';

	}

	return 0;
}