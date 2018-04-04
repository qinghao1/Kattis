#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef map<int, int> mii;
typedef unsigned __int128 ull;
#define LSOne(S) (S & (-S))

int n; ull k;

long long fact(int n) {
	long long ret = 1;
	while(n) ret *= n--;
	return ret;
}

string f(set<int> rem, ull kk) {
	if(rem.size() == 1) {
		cout << rem.front() << endl;
	} else {
		for()
	}
}

int main() {
	cin >> n >> k;
	while(n or k) {
		set<int> v(n);
		for(int i = 1; i <= n; i++) v.insert(i);
		f(v, k);
		cin >> n >> k;
	}
}