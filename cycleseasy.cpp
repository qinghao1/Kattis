#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> pii;
typedef map<int, int> mii;
#define LSOne(S) (S & (-S))

int main() {
	int t,n,k,x,y;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		bool g[12][12] = {0};
		cin >> n >> k;
		for(int i = 0; i < k; i++) {
			cin >> x >> y;
			--x;--y;
			g[x][y] = true;
			g[y][x] = true;
		}
		vi v(n);
		for(int i = 0; i < n; i++) {
			v[i] = i;
		}
		int ans = 0;
		do {
			int prev = -1;
			bool ok = true;
			for(auto const &x : v) {
				if(prev != -1) {
					if(g[prev][x]) {
						ok = false;
						break;
					}
				}
				prev = x;
			}
			if(g[v[n-1]][v[0]]) ok = false;
			if(ok) ++ans;
		} while (next_permutation(v.begin() + 1, v.end()));
		printf("Case #%d: %d\n", tt, (ans / 2) % 9901);
	}
}