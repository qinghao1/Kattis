#include<bits/stdc++.h>
using namespace std;

int main() {
	int t, n, T;
	cin >> n;
	while(n--) {
		cin >> T;
		if(T == 0) {
			cout << 0 << endl;
			continue;
		}
		set<int> s;
		int maxx = 0;
		while(T--) {
			cin >> t;
			if (s.find(t) != s.end()) {
				s.clear();
			}
			s.insert(t);
			maxx = max(maxx, (int) s.size());
		}
		cout << maxx << endl;
	}
}