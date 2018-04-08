#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef map<int, int> mii;
#define LSOne(S) (S & (-S))

ll _sieve_size;
bitset<10000010> bs;   // 10^7 should be enough for most cases
vi primes;   // compact list of primes in form of vector<int>


// first part

void sieve(ll upperbound) {          // create list of primes in [0..upperbound]
	_sieve_size = upperbound + 1;                   // add 1 to include upperbound
	bs.set();                                                 // set all bits to 1
	bs[0] = bs[1] = 0;                                     // except index 0 and 1
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
		// cross out multiples of i starting from i * i!
		for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);  // also add this vector containing list of primes
} }                                           // call this method in main method

bool isPrime(ll N) {                 // a good enough deterministic prime tester
	if (N <= _sieve_size) return bs[N];                   // O(1) for small primes
	for (int i = 0; i < (int)primes.size(); i++)
		if (N % primes[i] == 0) return false;
	return true;                    // it takes longer time if N is a large prime!
}                      // note: only work for N <= (last prime in vi "primes")^2

int main() {
	sieve(20010);
	int t; cin >> t;
	while(t--) {
		int n, d;
		cin >> n >> d;
		vector<pii> flowers(n);
		for(int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			flowers[i] = make_pair(x, y);
		}
		int cx = 0, cy = 0, cn = 0;
		double cd = 0;
		for(auto f : flowers) {
			double dist = sqrt(abs(f.first - cx) * abs(f.first - cx) + abs(f.second - cy) * abs(f.second - cy));
			if(cd + dist > d) break;
			cd += dist;
			cx = f.first; cy = f.second;
			++cn;
		}
		bool can = false;
		for(int i = cn; i >= 0; i--) {
			if(isPrime(i)) {
				cout << i << endl;
				can = true;
				break;
			}
		}
		if(!can) cout << 0 << endl;
	}
}