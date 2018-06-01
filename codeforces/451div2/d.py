n, m, k = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
vis = []
for i in range(n):
    vis.append(0)
ans = l = r = 0
cnt = 1
while(r < n):
    while(a[r]-a[l]+1 > m):
	    if(vis[l] == 0):
		    cnt -= 1
	    l += 1
    if cnt >= k:
        ans += 1
        vis[r] = 1;
        cnt -= 1
    r += 1
    cnt += 1
print(ans)