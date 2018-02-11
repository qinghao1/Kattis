import sys,math
t = int(sys.stdin.readline())
def avg(li):
	# if (len(l) == 0): print(l)
	return float(sum(li))/len(li)
for _ in xrange(t):
	sys.stdin.readline()
	a,b = [int(x) for x in sys.stdin.readline().split(' ')]
	comp = [int(x) for x in sys.stdin.readline().split(' ')]
	econ = [int(x) for x in sys.stdin.readline().split(' ')]
	comp.sort()
	comp1 = avg(comp)
	econ.sort()
	econ1 = avg(econ)
	ans = 0
	for i in range(0, len(comp)):
		if comp[i] < comp1 and comp[i] > econ1:
			ans += 1
	print(ans)
		# l = comp[i:]
		# # print(l)
		# ll = econ + comp[:i]
		# # 	print(ll)
		# print(avg(l))
		# print(comp1)
		# print(avg(ll))
		# print(econ1)
		# if avg(l) > comp1 and avg(ll) > econ1:
		# 	print(i)
		# 	break