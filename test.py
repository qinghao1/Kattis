N = 3
A = list(xrange(N))
c = [0] * N
i = 0
ct = 1
def next_perm():
	global N, A, c, i, ct
	if i >= N:
		return False;
	elif c[i] < i:
		if i & 1:
			A[c[i]], A[i] = A[i], A[c[i]]
		else:
			A[0], A[i] = A[i], A[0]
		c[i] += 1
		i = 0
		return True
	else:
		c[i] = 0
		i += 1
		return next_perm()

print(A)
while(next_perm()):
	print(A)
	ct += 1

print("Num of permutations: %d == %d!" % (ct, N))
