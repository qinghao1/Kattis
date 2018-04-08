#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	while(n) {
		bool grid[505][505] = {0};
		for(int i = 0; i < n; i++) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			for(int x = min(x1, x2); x < max(x1, x2); x++) 
				for(int y = min(y1, y2); y < max(y1, y2); y++)
					grid[x][y] = 1;
		}
		int ans = 0;
		for(int x = 0; x <= 500; x++)
			for(int y = 0; y <= 500; y++)
				ans += grid[x][y];
		cout << ans << endl;
		cin >> n;
	}
}