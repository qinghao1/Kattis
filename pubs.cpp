#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef map<int, int> mii;
#define LSOne(S) (S & (-S))

void bfs(vi &type, vvi g, int start) {
	queue<int> q;
	q.push(start);
	while(!q.empty()) {
		int node = q.front(); q.pop();
		for(auto const& nb : g[node]) {
			if(type[nb]) continue;
			type[nb] = type[node] == 1 ? 2 : 1;
			q.push(nb);
		}
	}
}

int main() {
	int m,n;
	cin >> n >> m;
	vi type(n);
	vvi g(n);
	for(int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b; --a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(auto const &v : g) {
		if(v.empty()) {
			cout << "Impossible" << endl;
			return 0;
		}
	}
	type[0] = 1;
	bfs(type,g,0);
	for(int i = 0; i < n; i++) {
		if(!type[i]) {
			type[i] = 1;
			bfs(type,g,i);
		}
	}
	for(int i = 0; i < n-1; i++) {
		cout << (type[i] == 1 ? "pub" : "house");
		cout << ' ';
	}
	cout << (type[n-1] == 1 ? "pub" : "house") << endl;
}