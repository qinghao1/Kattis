#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    long long c = 0;
    set<int> s;
    cin >> t;
    vector<int> h(t+2, 0);
    while(cin >> n) {
    	auto succ = s.upper_bound(n);
    	if (s.size() == 0) {
    		h[n] = 0;
    	} else if(succ == s.end()) {
    		// cout << max << "max" << endl;
    		h[n] = h[*(--succ)] + 1;
    	} else if (succ == s.begin()) {
    		h[n] = h[*succ] + 1;
    	} else {
    		h[n] = max(h[*(--succ)], h[*succ]) + 1;
    	}
    	c += (long long)h[n];
    	s.insert(n);
    	cout << c << endl;
    }
}