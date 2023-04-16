#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int n, ans = 0;
int map[3003][3003];
pair<int, int> loc1, loc2;
string ansdir;

int score(int dir) {	//U, D, L, R로 움직였을때의 양분 구함
	int sum = 0;
	switch (dir) {
	case 1:	//U
		if (loc1.second - 1 < 0) return -1;	//몸을 늘일 공간 없으면 음수 return
		for (int i = loc1.first; i <= loc2.first; i++) {
			sum += map[loc1.second - 1][i];
		}
		return sum;
	case 2: //D
		if (loc2.second + 1 >= n) return -1;
		for (int i = loc1.first; i <= loc2.first; i++) {
			sum += map[loc2.second + 1][i];
		}
		return sum;
	case 3: //L
		if (loc1.first - 1 < 0) return -1;
		for (int i = loc1.second; i <= loc2.second; i++) {
			sum += map[i][loc1.first - 1];
		}
		return sum;
	case 4: //R
		if (loc2.first + 1 >= n) return -1;
		for (int i = loc1.second; i <= loc2.second; i++) {
			sum += map[i][loc2.first + 1];
		}
		return sum;
	}
}

char maxdir(int u, int d, int l, int r) {	//U, D, L, R 중 최대 양분 구하고, 누적 합 갱신, 방향 문자열 저장
	int M = max(max(u, d), max(l, r));
	ans += M;
	if (M == u) return 'U';
	else if (M == d) return 'D';
	else if (M == l) return 'L';
	else return 'R';
}

void location(char c) {	//좌표 갱신
	switch (c) {
	case 'U':
		loc1.second -= 1;
		return;
	case 'D':
		loc2.second += 1;
		return;
	case 'L':
		loc1.first -= 1;
		return;
	case 'R':
		loc2.first += 1;
		return;
	}
}

int main() {
    
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	loc1.first = (n - 1) / 2; 	//1.x
	loc1.second = (n - 1) / 2; 	//1.y
	loc2.first = (n - 1) / 2 + 1;	//2.x
	loc2.second = (n - 1) / 2 + 1;	//2.y

	int idx = 0;
	while (1) {
		int U = 0, D = 0, L = 0, R = 0;
		U = score(1), D = score(2), L = score(3), R = score(4);	//U, D, L, R로 움직였을때의 양분 구함
		if (U <= 0 && D <= 0 && L <= 0 && R <= 0) {	//모두 음수라면 break;
			//cout << '*' << ++idx << " break\n";
			break;	
		}

		ansdir += maxdir(U, D, L, R);	//U, D, L, R 중 최대 양분 구하고, 누적 양분 갱신, 방향 문자열 저장

		location(ansdir.back());	//좌표 갱신
		//test
		//cout << '*' << ++idx << " U: " << U << " D: " << D << " L: " << L << " R: " << R << '\n';
		//cout << '*' << ansdir << ' ' << ans << '\n';
	}

	cout << ans << '\n' << ansdir;

	return 0;
}