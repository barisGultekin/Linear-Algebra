def MatrixDim(M): 
    return [len(M), len(M[0])]   

A = [
[1,0,0,2],
[0,1,0,3],
[0,0,1,4],
]

def M265BackSubs(A,b): 

    M265_solSet = [] 
    freeColumns = []

    rowPosition = 0
    columnPosition = 0

    fcIndex = 0

while(IN BOUNDARIES)
    if A[rowPosition][columnPosition] == 1:
        if checkAbove(A,columnPosition,rowPosition) == True and checkBelow(A,columnPosition,rowPosition) == True:
            continue
        else:
            freeColumns.append(rowPosition)
    elif A[rowPosition][columnPosition] == 0:
        if checkAbove(A,columnPosition,rowPosition) == True and checkBelow(A,columnPosition,rowPosition) == True:
            continue
        else:
            freeColumns.append(rowPosition)  
    else:
        freeColumns.append(rowPosition)
    rowPosition += 1
    columnPosition += 1

for i in range(rows):
    M265_solSet[i].append(b[i]-freeColumns[i])

        
    
