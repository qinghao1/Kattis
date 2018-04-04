#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef map<int, int> mii;
#define LSOne(S) (S & (-S))

int main() {
	long long n; cin >> n;
	unsigned __int128 fact = 1;
	for(long long i = 2; i <= n; i++) {
		// unsigned long long ii = i % 1000;
		// fact *= ii;
		fact *= i;
		while(fact % 10 == 0) {
			fact /= 10;
		}
		fact %= 1000000000000;
	}
	long long res = fact % 1000;
	if(n > 7 && res < 100) cout << 0;
	if(n > 7 && res < 10) cout << 0;
	cout << res << endl;
}