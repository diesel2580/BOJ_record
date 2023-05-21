#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

queue<pair<int, string>> q;

int D(int n) {
	if (n * 2 > 9999) return n * 2 % 10000;
	else return n * 2;
}
int S(int n) {
	if (n == 0) return 9999;
	else return n - 1;
}
int L(int n) {	//1234 >> 2341 //1245 >> 2451
	if (n < 1000) return n * 10;
	else {
		int tmp = n / 1000;
		n = (n % 1000) * 10;
		n += tmp;
		return n;
	}
}
int R(int n) {	//1234 >> 4123	//0001>>1000 //0021>>1002 //0123>>3012 // 
	int tmp = n % 10;
	n /= 10;
	n += tmp * 1000;
	return n;
}

int main() {

	int test;
	cin >> test;
	for (int T = 0; T < test; T++) {
		int visit[10009] = { 0, };
		//queue<pair<int, string>> q;
		int a, b;
		cin >> a >> b;
		q.push({ a, "" });

		while (!q.empty()) {
			int num = q.front().first;
			string str = q.front().second;
			q.pop();
			//cout << '*' << num << ' ' << str << '\n';
			if (num == b) {
				cout << str << '\n';
				break;
			}
			int d = D(num), s = S(num), l = L(num), r = R(num);
			/*q.push({ d, str + 'D' });
			q.push({ s, str + 'S' });
			q.push({ l, str + 'L' });
			q.push({ r, str + 'R' });*/
			if (d == b) {
				str += 'D';
				cout << str << '\n';
				break;
			}
			else {
				if (visit[d] == 0) {
					q.push({ d, str + 'D' });
					visit[d] = 1;
				}
			}
			if (s == b) {
				str += 'S';
				cout << str << '\n';
				break;
			}
			else {
				if (visit[s] == 0) {
					q.push({ s, str + 'S' });
					visit[s] = 1;
				}
			}
			if (l == b) {
				str += 'L';
				cout << str << '\n';
				break;
			}
			else {
				if (visit[l] == 0) {
					q.push({ l, str + 'L' });
					visit[l] = 1;
				}
			}
			if (r == b) {
				str += 'R';
				cout << str << '\n';
				break;
			}
			else {
				if (visit[r] == 0) {
					q.push({ r, str + 'R' });
					visit[r] = 1;
				}

			}
		}
		while (!q.empty()) q.pop();
	}

	return 0;
}