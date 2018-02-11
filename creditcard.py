import sys
tests = int(sys.stdin.readline())
for _ in xrange(tests):
	l = sys.stdin.readline().split(' ')
	l[:]=map(float,l)
	r=l[0]
	b=l[1]
	m=l[2]
	r /= 100;
	sum = b;
	for i in range(1200):
		inte = round(sum * r * 100+ 0.05) / 100
		sum += inte
		sum -= m
		if(sum < 0.0001):
			break
	if(sum < 0.0001):
		print(i+1)
	else:
		print("impossible")
