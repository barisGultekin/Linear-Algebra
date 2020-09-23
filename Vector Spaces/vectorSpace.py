def M265VS_VVA(v1,v2):
	if v1[0] < 9 or v2[0] < 9:
		print("Your vector doesn't belong to this vector space. Get the fuck out!")
		return
	else:
		result = [v1[0]*v2[0]-9*(v1[0]+v2[0])+90, v1[1]+v2[1]-2]
		if result[0] < 9:
			print("Your vector doesn't belong to this vector space. Get the fuck out!")
			return
		else:
			return result

def M265VS_SVM(a,v1):
	if v1[0] < 9 or v2[0] < 9:
		print("Your vector doesn't belong to this vector space. Get the fuck out!")
		return
	else:
		result = [((v1[0]-9)**a)+9, (a*v1[1])-(2*a)+2]
		if result[0] < 9:
			print("Your vector doesn't belong to this vector space. Get the fuck out!")
			return
		else:
			return result