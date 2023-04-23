#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

bool map[100000099];	//소수면 0
vector<int> v;

int main() {

	long long int a, b;
	cin >> a >> b;

	int cnt = 0;
	for (long long int i = 2; i < 10000001; i++) {
		if (map[i] == 0) {	//소수라면
			for (long long int j = i * i; j < 10000001; j += i) {
				map[j] = 1;
			}
		}
		if (map[i] != 0) continue;
		if (i > sqrt(b))continue;
		long long int prime = i * i;
		while (prime <= b) {
			if (prime >= a && prime <= b) cnt++;
			if (prime > LLONG_MAX / i) break;
			prime *= i;
		}
	}

	cout << cnt;

	


	return 0;
}