#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

typedef vector<int> vi;

int successive_difference(int a, int b) {
	return (b - a + 360000) % 360000;
}

void compute_prefix_function(vi& word, vi& pi) {
	pi.assign(word.size(), 0);
	pi[0] = -1;
	if (word.size() > 1) pi[1] = 0;
	int i = 2, k = 0;
	while (i < pi.size()) {
		if (word[i - 1] == word[k]) 
			pi[i++] = ++k;
		else if (k > 0) k = pi[k];
		else pi[i++] = 0;
	}
}

bool kmp(vi& sentence, vi& word) {
	int q = -1; vi pi;
	compute_prefix_function(word, pi);
	for (int i = 0; i < sentence.size(); ++i) {
		while (q >= 0 && word[q + 1] != sentence[i]) q = pi[q];
		if (word[q + 1] == sentence[i]) q++;
		if (q == word.size() - 1) {
			return true;
		}
	}
	return false;
}

int main() {

	// Take input
	int n;
	cin >> n;
	vi h1(n), h2(n);
	for (int i = 0; i < n; ++i) cin >> h1[i];
	for (int i = 0; i < n; ++i) cin >> h2[i];

	sort(h1.begin(), h1.end());
	sort(h2.begin(), h2.end());

	// Construct the pattern and sentence
	vi pat(n), sen(2 * n);
	for (int i = 0; i < n; ++i) pat[i] = successive_difference(h1[i], h1[(i + 1) % n]);
	for (int i = 0; i < n; ++i) 
		sen[i] = sen[i + n] = successive_difference(h2[i], h2[(i + 1) % n]);

	// Match
	cout << (kmp(sen, pat) ? "possible" : "impossible") << endl;

	return 0;
}

//Doesn't work??? WHY?

// #include<bits/stdc++.h>
// using namespace std;

// typedef vector<int> vi;
// typedef vector<vector<int> > vvi;
// typedef pair<int, int> pii;
// typedef vector<pii> vii;
// typedef map<int, int> mii;
// #define LSOne(S) (S & (-S))

// int main() {
// 	int n; cin >> n;
// 	vi c1(n+1), c2(n+1);
// 	for(int i = 0; i < n; i++){
// 		cin >> c1[i];
// 	}
// 	for(int i = 0; i < n; i++){
// 		cin >> c2[i];
// 	}
// 	c1[n] = c2[n] = 1e9;
// 	sort(c1.begin(), c1.end());
// 	sort(c2.begin(), c2.end());
// 	c1[n] = c1[0] + 360000;
// 	c2[n] = c2[0] + 360000;
// 	vi c1d(n*2), c2d(n);
// 	for(int i = 1; i < n+1; i++){
// 		c1d[i-1] = c1d[i-1 + n] = c1[i] - c1[i-1];
// 	}
// 	for(int i = 1; i < n+1; i++){
// 		c2d[i-1] = c2[i] - c2[i-1];
// 	}

// 	//KMP preprocess
// 	int b[200010] = {0};
// 	{
// 		int i = 0, j = -1; 
// 		b[0] = -1;
// 		while(i < c2d.size()) {
// 			while(j >= 0 and c2d[i] and c2d[j]) j = b[j];
// 			i++; j++;
// 			b[i] = j;
// 		}
// 	}

// 	//KMP match
// 	bool found = false;
// 	{
// 		int i = 0, j = 0;
// 		 while (i < c1d.size() && !found) {
// 		    while (j >= 0 && c1d[i] != c2d[j]) j = b[j]; // if different, reset j using b
// 		    i++; j++; // if same, advance both pointers
// 		    if (j == c2d.size()) { // a match found when j == m
// 		    	found = true;
// 			} 
// 		}
// 	}
// 	cout << (found ? "possible" : "impossible") << endl;
// }