#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int map[1002][1002];
bool visit[1002][1002];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q; 
queue<pair<int, int>> cheese, meltcheese;

void bfs(int n, int m) {

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			visit[i][j] = 0;
		}
	}

	q.push({ 0, 0 });
	visit[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x, ny = dy[i] + y;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || visit[nx][ny] == 1) continue;
			if (map[nx][ny] == 0) {
				q.push({ nx, ny });
				visit[nx][ny] = 1;
			}
			else {
				if (map[nx][ny] == 1) {
					map[nx][ny] = 2;
					cheese.push({ nx, ny });
				}
			}
		}
	}
}


int cheesemelt(int cheesecnt, int n, int m) {

	int melt = 0;
	while (!cheese.empty()) {
		int x = cheese.front().first, y = cheese.front().second;
		cheese.pop();
		map[x][y] = 1;

		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == 0 && visit[nx][ny] == 1) cnt++;
		}
		if (cnt >= 2) {
			melt++;
			//cout << x << ' ' << y << '\n';
			//cheesecnt--;
			//map[x][y] = 0;
			meltcheese.push({ x, y });
		}
	}
	while (!meltcheese.empty()) {
		int x = meltcheese.front().first, y = meltcheese.front().second;
		meltcheese.pop();
		map[x][y] = 0;
	}

	return melt;
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	int cheesecnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) cheesecnt++;
		}
	}
	//
	//cout << cheesecnt<<'\n';

	int time = 0;
	while (cheesecnt > 0) {

		bfs(n, m);
		int melt = cheesemelt(cheesecnt, n, m);
		cheesecnt -= melt;
		time++;

		//
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}*/
		//cout << "melt: " << melt <<' ' << "cheesecnt: " << cheesecnt << ' ' << "time: " << time << '\n';
		//cout << '\n';
	}

	cout << time;


	return 0;
}

// 
// 1. 외부 공기 탐색하면서 녹을 치즈 찾기 (큐에 좌표 넣어두기) 
//		일단 바깥 치즈면 다 넣어두고, 큐에서 빼면서 두 면 접촉인지 체크. 
// 2. 녹을 치즈 녹이기
//		여기서 시간 갱신. 
// 