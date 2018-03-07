#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> pii;
typedef map<int, int> mii;
#define LSOne(S) (S & (-S))

int c,p,x,l,a,b;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> c >> p >> x >> l;
	vvi g(c+5);
	vi brex(c+5, 0);
	vi total(c+5,0);
	vi remaining(c+5,0);
	brex[l] = 1;
	for(int i = 0; i < p; i++) {
		cin >> a >> b;
		total[a]++;
		remaining[a]++;
		total[b]++;
		remaining[b]++;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	queue<int> q;
	for(auto const &neighbor : g[l]) {
		remaining[neighbor]--;
		q.push(neighbor);
	}
	while(!q.empty()) {
		int node = q.front(); q.pop();
		if(brex[node]) continue;
		if(remaining[node] * 2 <= total[node]) {
			brex[node] = 1;
			for(auto const &neighbor : g[node]) remaining[neighbor]--;
		}
		if(brex[x]) break;
		if(brex[node]) for(auto const &neighbor : g[node]) q.push(neighbor);
	}
	cout << (brex[x] ? "leave" : "stay") << endl;
}