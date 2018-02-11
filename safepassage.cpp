#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef map<int, int> mii;
#define LSOne(S) (S & (-S))

int dp[1<<16] = {0};
int times[15];
int n;
int sideBit;
int mask;

void printBin(int x) {
	cout << endl;
	for(int i = 31; i >= 0; i--) {
		cout << ((x & (1<<i)) ? '1' : '0');
	}
	cout << endl;
}

int ctBits(int x) {
	int xx = x;
	int a = 0;
	while(xx) {
		++a;
		xx -= LSOne(xx);
	}
	return a;
}

int dpf(int x) {
	if(dp[x]) return dp[x];
	int minn = 1e9;
	int timetaken = -1;
	if(!x) return 0;
	if(x & sideBit) {
		for(int p1 = 0; p1 < n-1; p1++) {
			for(int p2 = p1+1; p2 < n; p2++) {
				int p1m = 1<<p1;
				int p2m = 1<<p2;
				if((x & p1m) and (x & p2m)) {
					int xx = x & mask;
					timetaken = max(times[p1], times[p2]);
					xx -= p1m;
					xx -= p2m;
					minn = min(dpf(xx) + timetaken, minn);
				}
			}
		}
	} else {
		int xx = x & mask;
		int xn = (~(x)) & mask;
		for(int p1 = 0; p1 < n; p1++) {
			int xx = x & mask;
			int p1m = 1<<p1;
			if(xn & p1m) {
				timetaken = times[p1];
				xx += p1m;
				minn = min(dpf(xx | sideBit) + timetaken, minn);
			}
		}
	}
	dp[x] = minn;
	// printBin(x);
	// cout << minn << ' ' << timetaken << endl;
	return dp[x];
}

int main() {
	cin >> n;
	sideBit = 1<<n; //1 is original side
	mask = (1<<n) - 1;
	for(int i = 0; i < n; i++)
		cin >> times[i];
	cout << dpf(mask | sideBit) << endl;
}