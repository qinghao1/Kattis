#include<bits/stdc++.h>
using namespace std;
#define LSOne(S) (S & (-S))

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t, m ,n;
	cin >> t;
	const int MAX = 30000;
	long long dp[2][MAX] = {0};
	dp[0][MAX / 2] = 1;
	bool curr = 0;
	while(t--) {
		cin >> m >> n;
		curr = !curr;
		int value = m * 130 + n;
		memset(dp[curr], 0 , sizeof dp[curr]);
		for(int j = 0; j < MAX; j++) {
			if(dp[!curr][j] > 0) {
				dp[curr][j + value] += dp[!curr][j];
				dp[curr][j] += dp[!curr][j];
			}
		}
	}
	cout << dp[curr][MAX / 2]-1 << endl;
}