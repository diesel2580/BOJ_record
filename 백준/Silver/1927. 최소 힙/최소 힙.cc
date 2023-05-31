#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp != 0) {
			pq.push(-tmp);
		}
		else {
			if (pq.empty()!=1) {
				cout << -pq.top() << '\n';
				pq.pop();
			}
			else {
				cout << '0' << "\n";
			}
		}
	}

	return 0;
}