import sys, math
t = int(sys.stdin.readline())
words = set()
freq = dict()
l = sys.stdin.readline().split(' ')
for word in l:
	words.add(word)
for _ in xrange(t - 1):
	l = sys.stdin.readline().split(' ')
	l[:] = l[1:]
	newwords = set(l)
	words = words.intersection(newwords)
	for word in words:
		if word in freq:
			freq[word] += 1
		else:
			freq[word] = 0
if len(words) == 0:
	print("ALL CLEAR")
else:
	for key, value in sorted(freq.iteritems(), key=lambda (k,v): (v,k)):
    		print(key)

