#include <iostream>
#include <stack>
using namespace std;

string str;
stack<char> s;

int main() {

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ')') {
			if (!s.empty() && s.top() == '(')
				s.pop();
			else s.push(str[i]);
		}
		else {
			s.push(str[i]);
		}
	}

	cout << s.size();

	return 0;
}