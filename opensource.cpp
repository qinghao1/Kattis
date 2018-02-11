#include<bits/stdc++.h>
using namespace std;
bool caps(string s) {
	return (int) s[0] < 97;
}
int main() {
	string s;
	map<string, set<string> > m;
	set<string> ss;
	string prev = "";
	while(getline(cin, s)) {
		// cout << s << endl;
		if(s.compare("0")==0) return 0;
		if(s.compare("1") == 0) {
			if(m.find(prev)==m.end())m[prev] = 0;
			vector<pair<int, string> > v;
			for(auto const &p : m) {
				v.push_back(make_pair(-p.second.size(), p.first));
			}
			sort(v.begin(), v.end());
			for(auto const &p : v) {
				printf("%s %d\n", p.second.c_str(), -p.first);
			}
			m.clear();
			ss.clear();
		} else {
			if (caps(s)) {
				prev = s;
			} else {
				if(ss.find(s)==ss.end()) {
					ss.insert(s);
					m[prev].insert(s);
				}else {
					for(auto const &p : m) {
						for(auto it = p.second.begin(); it != p.second.end(); ++it) {
							if((*it).compare(s) == 0) {
								p.second.erase(it);
							}
						}
					}
				}
			}
		}
	}
}