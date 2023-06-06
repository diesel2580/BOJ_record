#include <iostream>
#include <algorithm>
using namespace std;

long long int dist[100009];
long long int price[100009];

int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> dist[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}

	long long int sum = 0;
	long long int m = price[0];
	for (int i = 0; i < n - 1; i++) {
		m = min(price[i], m);
		sum += m * dist[i];
	}
	cout << sum;

	return 0;
}