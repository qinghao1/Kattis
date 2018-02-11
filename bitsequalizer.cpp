#include<bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		string a,b;
		cin >> a >> b;
		int moves = 0;
		int moves1 = 0;
		int moves0 = 0;
		int moves12 =0, moves02 = 0;
		int ones = 0;
		for(int i = 0; i < a.length(); i++) {
			char ca = a[i];
			char cb = b[i];
			if(ca == cb) continue;
			if(ca == '1' and cb == '0') ++moves0;
			if(ca == '0' and cb == '1') ++moves1;
			if(ca == '?') {
				++moves;
				if(cb == '1')++ones;
			}
		}
		if(moves0 > moves1 + ones) {
			printf("Case %d: -1\n", tt);
		} else {
			printf("Case %d: %d\n", tt, moves + max(moves1,moves0));
		}
	}
}