#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef map<int, int> mii;
#define LSOne(S) (S & (-S))

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))

double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }

int main() {
	int t; cin >> t;
	while(t--) {
		double r; cin >> r;
		int n; cin >> n;
		double deg, min, sec; cin >> deg >> min >> sec;
		min += sec / 60;
		deg += min / 60;
		set<double> cuts;
		double acc = 0;
		for(int i = 0; i < n; i++) {
			if(acc > (double) 360)
				acc -= 360;
			if(cuts.find(acc) != cuts.end()) break;
			cuts.insert(acc);
			acc += deg;
		}
		vector<double> spaces;
		double prevCut = -1;
		for(auto cut : cuts) {
			// cout << cut << endl;
			if(prevCut != -1) {
				spaces.push_back(abs(cut - prevCut));
			}
			prevCut = cut;
		}
		spaces.push_back(abs(360 - *cuts.rbegin()));
		double maxSpace = -1;
		for(auto s : spaces) {
			// cout << s << endl;
			if(s > maxSpace)
				maxSpace = s;
		}
		double area = r * r * PI * (maxSpace / 360);
		printf("%.6f\n", area);
	}
}