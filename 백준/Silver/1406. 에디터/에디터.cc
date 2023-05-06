#include <iostream>
#include <stack>
using namespace std;

string str, str2;
stack<char> s;
stack<char> s2;

int main() {

	int n;
	cin >> str;
	cin >> n;
	for (int i = 0; i < str.size(); i++) {
		s.push(str[i]);
	}
	for (int i = 0; i < n; i++) {
		char cmd;
		char tmp;
		cin >> cmd;
		switch (cmd) {
		case 'P': 
			//char tmp;
			cin >> tmp;
			s.push(tmp);
			break;
		case 'L': 
			if (s.empty()) break;
			tmp = s.top();
			s.pop();
			s2.push(tmp);
			break;
		case 'D': 
			if (s2.empty()) break;
			tmp = s2.top();
			s2.pop();
			s.push(tmp);
			break;
		case 'B':
			if (s.empty()) break;
			s.pop();
			break;
		}
	}
	while (!s2.empty()) {
		s.push(s2.top());
		s2.pop();
	}

	while (!s.empty()) {
		str2 += s.top();
		s.pop();
	}
	for (int i = str2.size() - 1; i >= 0; i--) {
		cout << str2[i];
	}

	return 0;
}
