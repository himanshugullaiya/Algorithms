def mergesort(arr, l, r):
	if l==r:
		return 
	m = (l+r)//2
	mergesort(arr, l, m)
	mergesort(arr, m+1, r)
	s = merge(arr, l , m ,r)

def merge(arr, l, m, r):
	temp = []
	i = l
	j = m+1

	while(i<m+1 and j<r+1):

		if arr[i] <= arr[j]:
			temp.append(arr[i])
			i += 1
		else:
			temp.append(arr[j])
			j += 1

	while(i < m+1):
		temp.append(arr[i])
		i += 1

	while(j < r+1):
		temp.append(arr[j])
		j += 1
	arr[l:r+1] = temp.copy()
	return arr

a = [6,5,7,1,10,7,3]
print(f" Unsorted Array: {a}")
mergesort(a, 0, len(a)-1)
print(f" Sorted Array:   {a}")


