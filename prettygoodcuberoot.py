import sys
import decimal
decimal.getcontext().prec = 1000
line = sys.stdin.readline()
while line:
	a = int(line)
	print(str(int(round(decimal.Decimal(a) ** (decimal.Decimal(1) / decimal.Decimal(3))))))
	line = sys.stdin.readline()