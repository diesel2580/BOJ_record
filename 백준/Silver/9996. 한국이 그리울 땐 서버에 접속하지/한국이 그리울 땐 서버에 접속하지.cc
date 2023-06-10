#include <iostream>
using namespace std;

int main() {

	int n;
	string key, arr;
	string s, e;
	cin >> n;
	cin >> key;
	int idx = 0;
	for (int i = 0; i < key.size(); i++) {
		idx++;
		if (key[i] == '*') break;
		s += key[i];
	}
	for (int i = idx; i < key.size(); i++) {
		e += key[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> arr;
		if (arr.size() < s.size() + e.size()) {
			cout << "NE" << '\n';
			continue;
		}
		int flag = 0;
		for (int j = 0; j < s.size(); j++) {
			if (arr[j] != s[j]) {
				flag = 1;
				break;
			}
		}
		//cout << arr.size() - e.size() << '*';
		for (int j = 0; j < e.size(); j++) {
			if (arr[j + arr.size() - e.size()] != e[j]) {
				flag = 1;
				break;
			}
		}
		
		if (flag == 1) cout << "NE" << '\n';
		else cout << "DA" << '\n';
		//a&bc
		//abcccc
	}

	return 0;
}
