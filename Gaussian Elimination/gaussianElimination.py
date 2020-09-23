M = [
[0,4,1],
[9,6,8],
[1,6,4]
]

b = [
3,
4,
9
]

def gaussianEliminator(M,b):
	map(float,M)
	map(float,b)
	n = len(b)

	x = [0 for index in range(n)]
	map(float,x)

	#Elimination
	for k in range(n-1):
		if abs(M[k][k]) == 0:
			for i in range(n):
				#M[i][k], M[i][k+1] = M[i][k+1], M[i][k]
				M[k][i], M[k+1][i] = M[k+1][i], M[k][i]
			b[k], b[k+1] = b[k+1], b[k]
		for i in range(k+1,n):
			if M[i][k] == 0:
				continue
			factor = M[k][k]/M[i][k]
			for j in range(k,n):
				M[i][j] = M[k][j]-(M[i][j]*factor)
			b[i] = b[k]-(b[i]*factor)
	print(M)

	#Back Substitution
	x[n-1] = b[n-1] / M[n-1][n-1]
	for i in range(n-2,-1,-1):
		sum_ax = 0
		for j in range(i+1,n):
			sum_ax += M[i][j] * x[j]
		x[i] = (b[i] - sum_ax) / M[i][i]

	return x

print(gaussianEliminator(M,b))

