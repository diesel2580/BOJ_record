#pragma warning (disable:4996)
#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

bool map[1005][1005];
bool visit[12][1002][1002];
queue<pair<int, int>> Q, Qcheck;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {

	int n, m, k;
	scanf("%d %d %d ", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	Q.push({ 0, 0 });
	Qcheck.push({ 1, 0 });
	int flag = 0;
	while (!Q.empty()) {
		int x = Q.front().first, y = Q.front().second;
		int cnt = Qcheck.front().first, wall = Qcheck.front().second;
		Q.pop();
		Qcheck.pop();
		if (x == n - 1 && y == m - 1) {
			//flag = min(flag, cnt);
			flag = cnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == 0 && visit[wall][nx][ny] == 0) {
				Q.push({ nx, ny });
				Qcheck.push({ cnt + 1, wall });
				visit[wall][nx][ny] = 1;
			}
			else if (map[nx][ny] == 1 && wall < k && visit[wall + 1][nx][ny] == 0) {
				if (cnt % 2 == 1) {	//낮
					Q.push({ nx, ny });
					Qcheck.push({ cnt + 1, wall + 1 });
					visit[wall + 1][nx][ny] = 1;
				}
				else {
					//Q.push({ nx, ny });
					//Qcheck.push({ cnt + 2, wall + 1 });
					Q.push({ x, y });
					Qcheck.push({ cnt + 1, wall });
					visit[wall][x][y] = 0;
				}
			}
		}
	}

	if (flag == 0) printf("-1");
	else printf("%d", flag);

	



	return 0;
}