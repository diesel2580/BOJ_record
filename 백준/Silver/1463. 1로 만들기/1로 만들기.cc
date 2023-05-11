#pragma warning (disable:4996)
#include <stdio.h>
#include <algorithm>
using namespace std;

//bottom-up

int cnt[1000000] = { 0, };

int main() {
	int n;
	scanf("%d", &n);


	for (int i = 2; i <= n; i++) {
		int m = cnt[i - 1];
		if (i % 2 == 0) {
			m = min(m, cnt[i / 2]);
		}
		if (i % 3 == 0) {
			m = min(m, cnt[i / 3]);
		}
		cnt[i] = m + 1;
	}

	printf("%d", cnt[n]);


	return 0;
}
