#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef map<int, int> mii;
#define LSOne(S) (S & (-S))

vector<string> splitString(string s, string delimiter) {
	size_t last = 0, next = 0;
	string token;
	vector<string> ret;
	while((next = s.find(delimiter, last)) != string::npos) {
		token = s.substr(last, next - last);
		ret.push_back(token);
		last = next + 1;
	}
	ret.push_back(s.substr(last));
	return ret;
}

unordered_map<string, int> stringIndex;
int dstoi(string s) {
	if(stringIndex.find(s) != stringIndex.end()) {
		return stringIndex[s];
	} else {
		stringIndex[s] = stringIndex.size();
		return stringIndex[s];
	}
}

const int MAX_N = 10000;
int erdos[MAX_N] = {0};
bool visited[MAX_N] = {0};
vvi g(MAX_N);
vector<string> firstnames;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string line;
	int erdosIndex = 0;
	while(getline(cin, line)) {
		vector<string> authors = splitString(line, " ");
		firstnames.push_back(authors.front());
		vector<int> idxs(authors.size());
		for(int i = 0; i < authors.size(); i++) {
			idxs[i] = dstoi(authors[i]);
			if(!erdosIndex and authors[i] == "PAUL_ERDOS") erdosIndex = idxs[i] + 1;
		}
		for(int i = 1; i < idxs.size(); i++) {
			g[idxs.front()].push_back(idxs[i]);
			g[idxs[i]].push_back(idxs.front());
		}
	}
	// BFS
	queue<pii> q;
	q.push(make_pair(erdosIndex - 1, 0));
	while(!q.empty()) {
		pii n = q.front(); q.pop();
		if(visited[n.first]) continue;
		erdos[n.first] = n.second;
		visited[n.first] = true;
		for(auto const& nb : g[n.first]) {
			q.push(make_pair(nb, n.second + 1));
		}
	}
	for(auto const &name : firstnames) {
		int idx = dstoi(name);
		if(name != "PAUL_ERDOS" and erdos[idx] == 0) {
			cout << name << ' ' << "no-connection" << endl;
		} else {
			cout << name << ' ' << erdos[idx] << endl;
		}
	}
}