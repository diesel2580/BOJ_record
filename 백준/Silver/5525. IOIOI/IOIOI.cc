#include <iostream>
#include <string>
using namespace std;

string str, p;

int main() {

	int n, m;
	cin >> n >> m >> str;
	p += 'I';
	for (int i = 0; i < n; i++) {
		p += "OI";
	}

	int cnt = 0;
	while (1) {
		if (str.find(p) == string::npos) {
			break;
		}
		else {
			cnt++;
			str[str.find(p)] = '*';
		}
	}

	cout << cnt;

	return 0;
}