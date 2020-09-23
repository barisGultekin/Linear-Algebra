def MatrixDim(M): 
    return [len(M), len(M[0])]   

A = [
[1,0,0,2],
[0,1,0,3],
[0,0,1,4],
]

columns = MatrixDim(A)[0] - 1
rows = MatrixDim(A)[1] - 1

lastPivotRowPosition = 0

columnPosition = 0
rowPosition = 0

result = True

def checkAbove(M,cp,rp):
    above = True
    for i in range(rp-1,-1,-1):
        if M[i][cp] == 0:
            continue
        else:
            above = False
            break
    return above

def checkBelow(M,cp,rp):
    below = True
    for j in range(rp+1,columns+1):
        if M[j][cp] == 0:
            continue
        else:
            below = False
            break
    return below

while columnPosition <= columns and rowPosition <= rows:
    if columnPosition <= columns:

        if A[rowPosition][columnPosition] == 0:
            for columnPosition in range(columns):
                if A[columnPosition][rowPosition] == 0:
                    continue
                elif A[columnPosition][rowPosition] == 1:
                    break
                else:
                    result = False
                    break
        elif A[rowPosition][columnPosition] == 1:
            if rowPosition >= lastPivotRowPosition:
                if checkAbove(A,columnPosition,rowPosition) == False:
                    result = False
                if checkBelow(A,columnPosition,rowPosition) == False:
                    result = False
            else:
                result = False
        else:
            result = False
        columnPosition += 1
    rowPosition += 1

print(result)
