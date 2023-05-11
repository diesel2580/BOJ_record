#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main() {

	int n;
	cin >> n;
	while (1) {
		int tmp;
		cin >> tmp;
		if (tmp == -1) 
			break;
		if (q.size() < n && tmp != 0) {
			q.push(tmp);
		}
		if (tmp == 0) q.pop();
	}

	if (q.empty()) {
		cout << "empty";
		return 0;
	}
	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
	}

	return 0;
}