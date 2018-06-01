n = int(input())
fa = list(map(int,input().split()))
c = list(map(int,input().split()))
ans = 1
for i in range(n-1):
    if c[i+1] != c[fa[i]-1]:
        ans += 1
print(ans)