#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> pii;
typedef map<int, int> mii;
#define LSOne(S) (S & (-S))

int main() {
	int t,x,y,sx,sy,n;
	cin >> t;
	while(t--) {
		vii points;
		cin >> x >> y;
		cin >> sx >> sy;
		cin >> n;
		while(n--) {
			cin >> x >> y;
			points.push_back(make_pair(x,y));
		}
		sort(points.begin(), points.end());
		// printf("SX %d SY %d\n", sx, sy);
		// for(auto const &p : points) {
		// 	printf("pX %d pY %d\n", p.first,p.second);
		// }
		int minD = 1e9;
		do {
			int d = 0;
			pii curr = make_pair(sx, sy);
			for(auto const &p : points) {
				d += abs(curr.first - p.first);
				d += abs(curr.second - p.second);
				curr = p;
			}
			d += abs(sx - curr.first);
			d += abs(sy - curr.second);
			minD = min(minD, d);
			// printf("currD %d\n",d);
		} while (next_permutation(points.begin(), points.end()));
		cout << minD << endl;
	}
}