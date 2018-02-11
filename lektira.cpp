#include<bits/stdc++.h>
using namespace std;
#define LSOne(S) (S & (-S))

int main() {
	string s;
	cin >> s;
	string mins = s;
	for(int i = 0; i < s.size() - 2; i++) {
		for(int j = i+1; j < s.size() - 1; j++) {
			string n;
			for(int k = i; k >= 0; k--) n += s[k];
			for(int k = j; k > i; k--) n += s[k];
			for(int k = s.size() - 1; k > j; k--) n += s[k];
			mins = min(mins, n);
			// cout << n << endl;
		}
	}
	cout << mins << endl;
}