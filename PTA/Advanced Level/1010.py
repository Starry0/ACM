d = {}
for i in range(10):
    d[chr(ord('0')+i)] = i
for i in range(26):
    d[chr(ord('a')+i)] = 10+i
def f(s, y):
    ans , cnt= 0, 1
    l = len(s)
    for i in range(l-1,-1,-1):
        ans += d[s[i]]*cnt
        cnt *= y
    return ans
str1, str2, tag, rad = input().strip().split()
if tag == '2':
    str1, str2 = str2, str1
n1 = f(str1, int(rad))
left = 1
for a in str2:
    left = max(left, d[a]+1)
right = n1 + 1 if n1 > left else left+1
ans = -1
while left <= right:
    mid = (left + right) >> 1
    n2 = f(str2, mid)
    if n2 == n1:
        ans = mid
        right = mid -1
    elif n2 > n1:
        right = mid - 1
    else :
        left = mid + 1
print(ans if ans != -1 else "Impossible")
