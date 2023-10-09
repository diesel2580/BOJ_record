#pragma warning (disable:4996)
#include <stdio.h>

int c = 0;
int S[10];
int j;
int k;

void C(int n, int m, int cnt) {
	//printf("%d %d %d\n", n, m, cnt);
	if (m == 0) {
		for (j = 0; j < k; j++) {
			printf("%d ", S[j]);
		}
		printf("\n");
	}
	if (m > 0) {
		for (int i = 1; i <= n; i++) {
			S[cnt] = i;
			C(n, m - 1, cnt + 1);
			//printf("%d %d %d, %d\n", n, m, cnt, i);
		}
	}

}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	k = m;
	C(n, m, c);


	return 0;
}