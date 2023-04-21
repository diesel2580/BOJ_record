#pragma warning (disable:4996)
#include <stdio.h>


int n, m;
int map[101][101], visit[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int t = 0;
int cnt = 0, tmp;

//m*n-- i*j 세로*가로 x*y n*m


void dfs(int i, int j) {
	for (int k = 0; k < 4; k++) {
		int X = i + dx[k], Y = j + dy[k];
		if (X >= 0 && Y >= 0 && X < m && Y < n) {
			if (map[X][Y] == 0 && visit[X][Y] == 0) {
				visit[X][Y] = 1;
				dfs(X, Y);
			}
			if (map[X][Y] == 1) {
				//printf("%d %d\n", X, Y);
				map[X][Y] = 2;
				cnt--;
			}
		}
	}
}


int main() {

	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				cnt++;
			}
		}
	}

	while(cnt>0){

		//printf("%d \n", cnt);
		

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				visit[i][j] = 0;
			}
		}
		tmp = cnt;
		dfs(0, 0);// 0이랑 닿은 치즈 2로


		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 2) {
					map[i][j] = 0;
				}
			}
		}//2였던 치즈 0으로
		t++;


	}

	printf("%d\n%d", t, tmp);

	return 0;
}