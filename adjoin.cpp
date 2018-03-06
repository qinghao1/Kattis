#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> pii;
typedef map<int, int> mii;
#define LSOne(S) (S & (-S))

int c,l,x,y;
bool visited[10005] = {0};
vector<vi> g;

int f(int node) {
	visited[node] = true;
	if(g[node].empty()) return 0;
	int maxD = 0, minD = 0;
	for(int i = 0; i < g[node].size(); i++) {
		if(!visited[g[node][i]]) {
			int nextD = f(g[node][i]) + 1;
			maxD = max(maxD, nextD);
			minD = min(minD, nextD);
		}
	}
	return (maxD + minD + 1) / 2;
}

int main() {
	cin >> c >> l;
	for(int i = 0; i < c; i++) {
		g.push_back(vi());
	}
	for(int i = 0; i < l; i++) {
		cin >> x >> y;
		g[x].push_back(y);
	}
	int curr = f(0);
	bool allVisited = true;
	int notVisited = -1;
	for(int i = 0; i < c; i++) {
		if(!visited[i]) {
			allVisited = false;
			notVisited = i;
			break;
		}
	}
	while(!allVisited) {
		curr += f(notVisited);
		++curr;
		allVisited = true;
		for(int i = 0; i < c; i++) {
			if(!visited[i]) {
				allVisited = false;
				notVisited = i;
				break;
			}
		}
	}
	cout << curr << endl;
}