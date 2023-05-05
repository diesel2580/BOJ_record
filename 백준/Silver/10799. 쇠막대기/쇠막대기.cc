#include <iostream>
#include <stack>
using namespace std;

stack<char> s;
string str;

int main() {

	cin >> str;
	int sum = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push(str[i]);
		}
		else {	//)
			if (str[i - 1] == '(') {	//lazer
				s.push(str[i]);
				sum += s.size() - 2;
				s.pop();
				s.pop();
			}
			else {	//막대 끝
				sum += 1;
				s.pop();
			}
		}
	}

	cout << sum;

	return 0;
}
