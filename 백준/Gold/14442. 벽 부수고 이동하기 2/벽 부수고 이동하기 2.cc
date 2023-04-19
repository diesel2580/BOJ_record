#pragma warning (disable:4996)
#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;

int map[1005][1005];
int visit[12][1005][1005];	//좌표, 몇 번째 부순 벽인지
queue<pair<int, int>> Qloc, Qcheck;	//x, y	//cnt, flag
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {

	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	//cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
			//cin >> map[i][j];
		}
	}

	Qloc.push({ 0, 0 });
	Qcheck.push({ 1, 0 });
	int flag = 0;
	while (!Qloc.empty()) {
		int x = Qloc.front().first, y = Qloc.front().second;
		int cnt = Qcheck.front().first, wall = Qcheck.front().second;
		Qloc.pop();
		Qcheck.pop();

		if (x == n - 1 && y == m - 1) {
			flag = cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int xnext = x + dx[i], ynext = y + dy[i];
			if (xnext >= 0 && ynext >= 0 && xnext < n && ynext < m) {
				if (map[xnext][ynext] == 0 && visit[wall][xnext][ynext] == 0) {
					Qloc.push({ xnext, ynext });
					Qcheck.push({ cnt + 1, wall });
					visit[wall][xnext][ynext]= 1;
				}
				else if (map[xnext][ynext] == 1 && wall < k && visit[wall+1][xnext][ynext] == 0) {
					Qloc.push({ xnext, ynext });
					Qcheck.push({ cnt + 1, wall + 1 });
					visit[wall + 1][xnext][ynext] = 1;
				}
			}
		}
	}

	if (flag == 0) printf("-1");
	else printf("%d", flag);

	/*if (flag == 1) cout << "-1";
	else cout << flag;*/



	return 0;
}