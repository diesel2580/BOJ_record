#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int num[1000000];
int findnum[1000000];

void b_search(int start, int end, int target) {
	int mid = (start + end) / 2;
	if (num[mid] == target) {
		cout << "1\n";
		return;
	}
	else if (start > end) {
		cout << "0\n";
		return;
	}
	if (num[mid] > target) b_search(start, mid - 1, target);
	if (num[mid] < target) b_search(mid + 1, end, target);
}

int main() {

	int test;
	cin >> test;
	for (int T = 0; T < test; T++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		sort(num, num + n);
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> findnum[i];
		}
		for (int i = 0; i < m; i++) {
			b_search(0, n - 1, findnum[i]);
		}
	}

	return 0;
}