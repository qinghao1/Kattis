import sys, math
n = int(sys.stdin.readline())
fact = 1
for i in range(1,n+1):
	fact *= i
	while(fact % 10 == 0):
		fact /= 10
print(fact % 1000)