#include<bits/stdc++.h>
using namespace std;
#define LSOne(S) (S & (-S))

set<int> masks;

int main() {
	int m, n, a, b;
	cin >> n >> m;
	long long total = 0;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		--a;--b;
		int mask = (1 << a) + (1 << b);
		masks.insert(mask);
	}
	for(int i = 0; i < (1 << n); i++) {
		bool valid = true;
		for(auto const &m : masks) {
			if ((i & m) == m) {
				valid = false;
				break;
			}
		}
		// printf("%d %d\n", i, valid);
		if(valid) ++total;
	}
	cout << total << endl;
}