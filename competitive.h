#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef map<int, int> mii;
#define LSOne(S) (S & (-S))

map<string, int> stringIndex;
//Starts from 0
int dstoi(string s) {
  if(stringIndex.find(s) != stringIndex.end()) {
    return stringIndex[s];
  } else {
    stringIndex[s] = stringIndex.size();
    return stringIndex[s];
  }
}

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
}

int ctBits(size_t x) {
  int ct = 0;
  while(x) {
    x -= (x & (-x));
    ++ct;
  }
  return ct;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}