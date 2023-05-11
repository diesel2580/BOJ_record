#include <iostream>
using namespace std;

int map[13];

int main() {

	int n;
	cin >> n;

	map[1] = 1;
	map[2] = 2;
	map[3] = 4;

	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		for (int i = 4; i <= m; i++) {
			map[i] = map[i - 1] + map[i - 2] + map[i - 3];
		}
		cout << map[m] << '\n';
	}

	

	return 0;
}