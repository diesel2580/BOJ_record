#include <iostream>
using namespace std;

string str;

int main() {

	cin >> str;
	int flag = 0;	//0이면 다 더하기
	int num = 0, sum = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			num *= 10;
			num += str[i] - '0';
		}
		else {
			if (flag == 0) {
				sum += num;
			}
			else {
				sum -= num;
			}
			num = 0;
			if (str[i] == '-') flag = 1;
		}
		
	}
	if (flag == 0) sum += num;
	else sum -= num;

	cout << sum;

	return 0;
}