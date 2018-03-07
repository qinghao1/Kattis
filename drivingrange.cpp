#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef map<int, int> mii;
#define LSOne(S) (S & (-S))

class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int n,m;

int main() {
	cin >> n >> m;
	UnionFind uf(n);
	vector<pair<int, pair<int, int> > > v;
	for(int i = 0; i < m; i++) {
		int a,b,w;
		cin >> a >> b >> w;
		v.push_back(make_pair(w, make_pair(a,b)));
	}
	sort(v.begin(), v.end());
	int maxW = 0;
	for(auto const &t : v) {
		if(uf.isSameSet(t.second.first, t.second.second)) continue;
		maxW = max(maxW, t.first);
		uf.unionSet(t.second.first, t.second.second);
	}
	if(uf.numDisjointSets() == 1) {
		cout << maxW << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
}