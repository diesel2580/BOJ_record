#pragma warning (disable:4996)
#include <stdio.h>

int main() {

	int n;
	scanf("%d", &n);

	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		for (int j = 0; j < (n - 1 - i) * 2; j++) {
			printf(" ");
		}
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = n-2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		for (int j = 0; j < (n - i - 1) * 2; j++) {
			printf(" ");
		}
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
/*
5
0*........*	8
1**......**	6
2***    ***	n-1-i)*2
3****  ****
4**********
3****  ****	2
2***    ***	4	
1**      **	6
0*        *	8 (n-i-1)*2

*/