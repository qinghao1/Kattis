#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef map<int, int> mii;
#define LSOne(S) (S & (-S))

typedef long long LL;
#define INF 1000000000000LL

struct Edge {
  int u, v;
  LL cap, flow;
  Edge() {}
  Edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;
  
  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void AddEdge(int u, int v, LL cap) {
    if (u != v) {
      E.emplace_back(Edge(u, v, cap));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(Edge(v, u, 0));
      g[v].emplace_back(E.size() - 1);
    }
  }

  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }

  LL DFS(int u, int T, LL flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        LL amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (LL pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  LL MaxFlow(int S, int T) {
    LL total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (LL flow = DFS(S, T))
        total += flow;
    }
    return total;
  }
};

int r,c,rr,cc;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int idx(int x, int y) {
  return x * c + y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> r >> c;
  Dinic dinic(2 * r * c + 1);
  int source = 2 * r * c;
  for(int x = 0; x < r; x++) {
    for(int y = 0; y < c; y++) {
      if(x == 0 or y == 0 or x == r-1 or y == c-1) {
        dinic.AddEdge(source, idx(x, y), INF);
      }
      int t; cin >> t;
      dinic.AddEdge(idx(x,y), r*c+idx(x,y), t);
      for(int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if(nx < 0 or nx == r or ny < 0 or ny == c) continue;
        dinic.AddEdge(r*c+idx(x,y), idx(nx,ny), INF);
      }
    }
  }
  cin >> rr >> cc;
  cout << dinic.MaxFlow(source, r*c+idx(rr,cc)) << endl;
}