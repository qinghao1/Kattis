#include<bits/stdc++.h>
using namespace std;
#define LSOne(S) (S & (-S))
int n;
vector<int> vi;
long long totalWeight = 0;

void f(int curr, long long w) {
	if(w >= 200) return;
	if(curr == n) {
		totalWeight -= w;
		return;
	} else {
		f(curr + 1, w);
		f(curr + 1, w + vi[curr]);
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		vi.push_back(t);
		totalWeight += t * (((long long) 1) << (n - 1));
	}
	f(0, 0);
	cout << totalWeight << endl;
}