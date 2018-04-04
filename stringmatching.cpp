#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef map<int, int> mii;
#define LSOne(S) (S & (-S))

int main() {
	int t; cin >> t;
	while(t--) {
		string s1, s2;
		getline(cin, s1);
		int q; cin >> q;
		while(q--) {
			cin >> s2;
			size_t last = 0, next = 0;
			long long num = 0;
			while(next != string::npos) {
				next = s1.find(s2, last);
				if(next != string::npos) ++num;
				last = next + 1;
			}
			cout << num << endl;
		}
	}
}