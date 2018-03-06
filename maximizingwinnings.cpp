#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef map<int, int> mii;
#define LSOne(S) (S & (-S))

vector<vi> rooms;
map<pair<int,int>, pair<int,int>> dp;
int t, n, m;

pii dpf(int r, int turns) {
	pii p = make_pair(r, turns);
	if(dp.find(p) != dp.end()) return dp[p];
	if(turns == 0) return make_pair(0, 0);
	int maxi = -1, mini = 1e9;
	for(int r2 = 0; r2 < n; r2++) {
		pii nxt = dpf(r2, turns - 1);
		maxi = max(maxi, nxt.first + rooms[r][r2]);
		mini = min(mini, nxt.second + rooms[r][r2]);
	}
	dp[p] = make_pair(maxi, mini);
	return dp[p];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while(n > 0) {
		rooms = vector<vi>(n);
		for(int i = 0; i < n; i++) {
			rooms[i] = vi(n);
			for(int j = 0; j < n; j++) {
				cin >> rooms[i][j];
			}
		}
		cin >> m;
		pii p = dpf(0,m);
		cout << p.first << ' ' << p.second << endl;
		rooms.clear();
		dp.clear();
		cin >> n;
	}
}