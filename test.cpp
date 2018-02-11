#include<bits/stdc++.h>
using namespace std;
// https://en.wikipedia.org/wiki/Heap%27s_algorithm
const int N = 5;
int A[N];
int c[N] = {0};
int i = 0;
int ct = 0;
void p() {
	for(int j = 0; j < N; j++) {
		printf("%d ", A[j]);
	}
	printf("\n");
	++ct;
}
bool next_perm() {
	if(i >= N) return false;
	if(c[i] < i) {
		if (i & 1) {
			swap(A[c[i]], A[i]);
		} else {
			swap(A[0], A[i]);
		}
		++c[i];
		i = 0;
		return true;
	} else {
		c[i] = 0;
		++i;
		return next_perm();
	}
}
int main() {
	for(int j = 1; j <= 5; j++) A[j-1] = j;
	p();
	while(next_perm()) p();

	printf("Num of permutations: %d == %d!\n", ct, N);
}