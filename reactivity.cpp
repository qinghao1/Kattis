#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> pii;
typedef map<int, int> mii;
#define LSOne(S) (S & (-S))

int main() {
	int n, k, x, y;
	cin >> n >> k;
	vector<vi> g(n);
	vi deg(n, 0);
	for(int i = 0; i < k; i++) {
		cin >> x >> y;
		g[x].push_back(y);
		deg[y]++;
	}
	vi ans;
	queue<int> q;
	for(int i = 0; i < n; i++) {
		if(deg[i] == 0) q.push(i);
	}
	while(q.size() == 1) {
		int curr = q.front(); q.pop();
		ans.push_back(curr);
		for(auto const &nxt : g[curr]) {
			--deg[nxt];
			if(deg[nxt] == 0) {
				q.push(nxt);
			}
		}
	}
	if(ans.size() != n) {
		printf("back to the lab");
	} else {
		for(int i = 0; i < ans.size() - 1; i++) printf("%d ", ans[i]);
		printf("%d", ans.back());
	}
}