#include<bits/stdc++.h>
using namespace std;
int main() {
	int m,n;
	while(scanf("%d %d",&m,&n)==2 and (m or n)) {
	unordered_set<int> s;
	while(m--) {
		int t;
		cin >> t;
		s.insert(t);
	}
	int ans = 0;
	while(n--) {
		int t;
		cin >> t;
		if (s.find(t) != s.end()) ++ans;
	}
	cout << ans << endl;
	}
}