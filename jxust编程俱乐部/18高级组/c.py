a = [0, 1]
for i in range(2,210):
	a.append(6*a[i-1]-a[i-2])
n = int(input())
print(a[n]*a[n])