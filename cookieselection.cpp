#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	priority_queue<int> maxh;
	priority_queue<int> minh;
	while(cin >> s) {
		if (s.compare("#") != 0) {
			int x = stoi(s);
			if (maxh.empty() || x < maxh.top()) {
				maxh.push(x);
			} else {
				minh.push(-x);
			}
		} else {
			cout << -minh.top() << endl;
			minh.pop();
		}
		if(maxh.size() > minh.size()) {
			minh.push(-maxh.top());
			maxh.pop();
		} else if (minh.size() > maxh.size() + 1) {
			maxh.push(-minh.top());
			minh.pop();
		}
	}
}