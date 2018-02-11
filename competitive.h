#include<bits/stdc++.h>
ios_base::sync_with_stdio(0);
using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef map<int, int> mii;
#define LSOne(S) (S & (-S))

class FenwickTree {
private:;
  vi ft;

public:
  FenwickTree() {}
  // initialization: n + 1 zeroes, ignore index 0
  FenwickTree(int n) { ft.assign(n + 1, 0); }

  int rsq(int b) {                                     // returns RSQ(1, b)
    int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }

  int rsq(int a, int b) {                              // returns RSQ(a, b)
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

  // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
  void adjust(int k, int v) {                    // note: n = ft.size() - 1
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};

map<string, int> ss;
int dstoi(string s) {
	if(ss.find(s) != ss.end()) {
		return ss[s];
	} else {
		ss[s] = ss.size();
		return ss[s];
	}
}