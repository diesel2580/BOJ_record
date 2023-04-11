#include <iostream>
#include <algorithm>
using namespace std;

long long int n, m;
int num[1000009];
int flag = 0;

void search(int start, int end) {

	long long int wood = 0;
	int mid = (start + end) / 2;
	long long int tmpW = 2000000000, tmpH = mid;;

	if (start > end) {
		cout << tmpH;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (num[i] - mid > 0)
			wood += num[i] - mid;
	}
	if (wood == m) {
		cout << mid;
		return;
	}
	else if (wood > m) {
		search(mid + 1, end);
		if (tmpW < wood) {
			tmpW = wood;
			tmpH = mid;
		}
	}
	else {
		search(start, mid - 1);
	}
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	
	search(0, num[n - 1]);


	return 0;
}