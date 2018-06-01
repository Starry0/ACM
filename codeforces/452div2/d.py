import math
n = int(input())
if n < 5:
    print(n*(n-1)//2)
    exit()
a = 0
k = int(math.log10(2*n))
for i in range(k):
    a = a*10+9
ans = 0
for i in range(9):
    r = int(str(i)+str(a))
    if r > 2*n-1:
        break
    elif r < 1+n:
        ans += r//2
    elif r < 2*n:
        ans += (2*n-r+1)//2
print(ans)