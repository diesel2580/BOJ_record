#include <iostream>
#include <queue>
#include <utility>
using namespace std;
 
queue<pair<pair<int, int>, int>> q;
int map[1002][1002], dist[1002][1002];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	int sx, sy;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				q.push({ { i, j }, 0 });
				sx = i;
				sy = j;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		dist[x][y] = cnt;
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x, ny = dy[i] + y;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == 0 || dist[nx][ny]!=0 || (nx==sx && ny==sy)) continue;
			q.push({ {nx, ny}, cnt + 1 });
			dist[nx][ny] = cnt + 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0 && dist[i][j] == 0) dist[i][j] = -1;
			if (i == sx && j == sy) dist[i][j] = 0;
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}