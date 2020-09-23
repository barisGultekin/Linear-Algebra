M = [
[2,4,1],
[9,6,8],
[1,6,4]
]

b = [
3,
4,
9
]

#operation = [[0 for i in range(len(M)-1)] for j in range(len(M)-1)]
#for i in range(len(operation)):
	#for k in range(len(identity)):
		#if i == k:
			#operation[i][k] = 1

#operations = [100][][]
numberOfOperations = 0

def gaussianEliminator(M,b):
	map(float,M)
	map(float,b)
	n = len(b)

	x = [0 for index in range(n)]
	map(float,x)

	identityIndex = 0

	#Elimination
	for k in range(n-1):
		#Partial Pivoting
		if abs(M[k][k]) == 0:
			for i in range(n):
				M[k][i], M[k+1][i] = M[k+1][i], M[k][i]
			b[k], b[k+1] = b[k+1], b[k]
		#Row Operations
		for i in range(k+1,n):
			if M[i][k] == 0:
				continue
			factor = M[k][k]/M[i][k]
			for j in range(k,n):
				M[i][j] = M[k][j]-(M[i][j]*factor)
				#operation[]
			b[i] = b[k]-(b[i]*factor)

	#Back Substitution
	x[n-1] = b[n-1] / M[n-1][n-1]
	for i in range(n-2,-1,-1):
		sum_ax = 0
		for j in range(i+1,n):
			sum_ax += M[i][j] * x[j]
		x[i] = (b[i] - sum_ax) / M[i][i]

	return x

gaussianEliminator(M,b)

def gaussianEliminator(M,b):
	map(float,M)
	map(float,b)
	n = len(b)

	x = [0 for index in range(n)]
	map(float,x)

    #Elimination
	for k in range(n-1):
        #Partial Pivoting
		if M[k][k] == 0:
			for i in range(n):
				M[k][i], M[k+1][i] = M[k+1][i], M[k][i]
        #Row Operations
		for i in range(k+1,n):
			if M[i][k] == 0:
				continue
			factor = M[k][k]/M[i][k]
			for j in range(k,n):
				M[i][j] = M[k][j]-(M[i][j]*factor)
			b[i] = b[k]-(b[i]*factor)
    #Back Substitution
	x[n-1] = b[n-1] / M[n-1][n-1]
	for i in range(n-2,-1,-1):
		sum_ax = 0
		for j in range(i+1,n):
			sum_ax += M[i][j] * x[j]
		x[i] = (b[i] - sum_ax) / M[i][i]

	print("Eliminated Matrix: ",M)
	return x

print("\nVector of roots of the equation: ",gaussianEliminator(M,b))
