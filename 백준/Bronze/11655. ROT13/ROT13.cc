#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

char c[109];

int main() {

	fgets(c, 102, stdin);
	int len = (int)strlen(c) - 1;

	for (int i = 0; i < len; i++) {
		if (c[i] >= 'A' && c[i] <= 'Z') {
			if (c[i] - 'A' >= 13) printf("%c", c[i] - 13);
			else printf("%c", c[i] + 13);
		}
		else if (c[i] >= 'a' && c[i] <= 'z') {
			if (c[i] - 'a' >= 13) printf("%c", c[i] - 13);
			else printf("%c", c[i] + 13);
		}
		else {
			printf("%c", c[i]);
		}

	}

	return 0;
}