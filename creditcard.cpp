#include<bits/stdc++.h>
using namespace std;
double eps = 1e-3;
int main() {
	int t;
	double r,b,m;
	cin >> t;
	while(t--) {
		scanf("%lf %lf %lf", &r, &b, &m);
		r/=100;
		bool paid = false;
		for(int i = 1; i <= 1200; i++) {
			double interest = b * r;
			interest = round(interest * 100) / 100;
			b += interest;
			b = round(b * 100) / 100;
			b -= m;
			if (b < eps) {
				cout << i << endl;
				paid = true;
				break;
			}
		}
		if(!paid)cout << "impossible\n";
	}
}