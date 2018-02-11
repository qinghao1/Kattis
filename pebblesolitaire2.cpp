#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef map<int, int> mii;
#define LSOne(S) (S & (-S))
mii m;
int ctBits(int x) {
	int xx = x;
	int a = 0;
	while(xx) {
		++a;
		xx -= LSOne(xx);
	}
	return a;
}

void printBin(int x) {
	cout << endl;
	for(int i = 31; i >= 0; i--) {
		cout << ((x & (1<<i)) ? 'o' : '-');
	}
	cout << endl;
}

int f(int x) {
	// printBin(x);
	if(m.find(x) != m.end()) return m[x];
	bool canMove = false;
	int mini = 1e9;
	for(int i = 0; i < 21; i++) {
		if(!(x & (1<<i)) and (x & (1<<(i+1))) and (x & (1<<(i+2)))) {
			canMove = true;
			int xx = ((x | (1<<i)) & ~(1<<(i+2))) & ~(1<<(i+1));
			// printBin(xx);
			// cout << endl;
			mini = min(mini, f(xx));
		}
	}
	for(int i = 2; i < 23; i++) {
		if(!(x & (1<<i)) and (x & (1<<(i-1))) and (x & (1<<(i-2)))) {
			canMove = true;
			int xx = ((x | (1<<i)) & ~(1<<(i-1))) & ~(1<<(i-2));
			// printBin(xx);
			// cout << endl;
			mini = min(mini, f(xx));
		}
	}
	if(canMove) {
		m[x] = mini;
	} else {
		m[x] = ctBits(x);
	}
	return m[x];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int x = 0;
		char c;
		for(int i = 1; i <= 23; i++) {
			cin >> c;
			if(c == 'o')
				x |= (1<<(23-i));
		}
		cout << f(x) << endl;
	}
}