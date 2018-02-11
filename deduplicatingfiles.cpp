#include<bits/stdc++.h>
using namespace std;
int hashf(string s) {
	int x = (1<<8)-1;
	for(auto const &c : s) {
		x ^= ((int) c) % 128;
	}
	cout << x << endl;
	return x;
}
int main() {
	string s;
	int t;
	while(cin >> t && t){
		map<int, set<string> > m;
		getline(cin, s);
		int ct = 0;
		int ct2 = 0;
		while(t--) {
			getline(cin, s);
			int h = hashf(s);
			if(m[h].find(s) == m[h].end()) {
				//New
				ct2 += 1;
				ct += m[h].size();
				m[h].insert(s);
			} else {
				//Old
				cout << "old" << endl;
			}
		}
		cout << ct2 << ' ' << ct << endl;
	}
}