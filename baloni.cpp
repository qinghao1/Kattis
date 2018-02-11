#include<bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	int arr[1000000] = {0};
	while(t--) {
		cin >> n;
		if(arr[n] > 0) {
			--arr[n];
		}
		++arr[n-1];
	}
	int sum = 0;
	for(int i = 0; i < 1000000; i++) sum+=arr[i];
	cout << sum;
}