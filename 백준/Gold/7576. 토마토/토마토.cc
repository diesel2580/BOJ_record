#pragma warning (disable:4996)
#include <stdio.h>
#include <queue>
using namespace std;

queue<int> X;//행
queue<int> Y;
queue<int> cnt;

int S[1009][1009];

int main() {
	int n, m;
	int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {//행
		for (int j = 0; j < m; j++) {
			scanf("%d", &S[i][j]);
			if (S[i][j] == 1) {
				X.push(i);
				Y.push(j);
				cnt.push(0);
			}
		}
	}
	int t = 0;
	while (X.empty()!=1 || Y.empty()!=1) {
		//printf("\n");
		t = cnt.front();
		int a = X.front(), b = Y.front();

		X.pop();
		Y.pop();
		cnt.pop();

		for (int i = 0; i < 4; i++) {
			if (a + dx[i] >= 0 && b + dy[i] >= 0 && a + dx[i] < n && b + dy[i] < m && S[a + dx[i]][b + dy[i]] == 0) {
				X.push(a + dx[i]);
				Y.push(b + dy[i]);
				cnt.push(t + 1);
				S[a+dx[i]][b+dy[i]] = 1;
			}
		}
		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", S[i][j]);
			}
			printf("\n");
		}
		//printf("X:%d Y:%d", X.size(), Y.size());
		*/
	}

	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (S[i][j] == 0) {
				k++;
			}
		}
	}
	if (k != 0) {
		printf("-1");
	}
	else {
		printf("%d",t);
	}


	return 0;
}