#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	char T[1000];
	int n = (int) strlen(gets(T));
	T[n++] = '$';
	T[--n] = 0;
	for(int i = 0; i < n; i++)
		printf("%d %s\n", i, T+i);
}