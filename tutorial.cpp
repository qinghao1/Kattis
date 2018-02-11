#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int  llui;
llui t,m,n;
llui fac(llui a) {
	llui ans = 1;
	while(a > 0 && ans < m) {
		ans *= a;
		a--;
	};
	return ans < m;
}
llui p2(llui a) {
	return a > 30 || (1 << a) < m;
}

int main() {
	cin >> m >> n >> t;
	// cout << m << endl << n << endl << t;
	switch(t) {
		case 1: cout << (fac(n) ? "AC" : "TLE"); break;
		case 2: cout << (p2(n) ?  "AC" : "TLE"); break;
		case 3: cout << ((n*n*n*n) > m ? "TLE" : "AC"); break;
		case 4: cout << (n*n*n > m ? "TLE" : "AC"); break;
		case 5: cout << (n*n > m ? "TLE" : "AC"); break;
		case 6: cout << (n*log2(n) > m ? "TLE" : "AC"); break;
		case 7: cout << (m > n ? "AC" : "TLE"); break;
	}
}