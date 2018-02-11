import sys, math
l = sys.stdin.readline().split(' ')
l[:]=map(int,l)
m,n,t = l
if(t==1):
	print("TLE" if (n >= 30 or math.factorial(n) > m) else "AC")
elif (t==2) :
	print("TLE" if math.pow(2,n) > m else "AC")
elif (t==3) :
	print("TLE" if (n*n*n*n) > m else "AC")
elif (t==4) :
	print("TLE" if (n*n*n) > m else "AC")
elif (t==5) :
	print("TLE" if (n*n) > m else "AC")
elif (t==6) :
	print("TLE" if (n*math.log(n,2)) > m else "AC")
elif (t==7) :
	print("TLE" if (n) > m else "AC")
