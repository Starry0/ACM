#不知为啥老是答案错误，明明是按照C++提交正确的代码改的
n, k = map(int, input().strip().split())
arr = map(int, input().strip().split())
x, y = [],[]
MAXY = 0
def f(xx):
    global MAXY
    xxx = xx
    ans = 0
    while xxx%2 == 0:
        ans += 1
        xxx /= 2
    x.append(ans)
    xxx = xx
    ans = 0
    while xxx%5 == 0:
        ans += 1
        xxx /= 5
    y.append(ans)
    MAXY += ans
dp = [[-1]*4000 for row in range(220)]
for i in arr:
    f(i)
dp[0][0] = 0
for i in range(0,n):
    for j in range(k,0,-1):
        for l in range(MAXY,-1,-1):
            if l-y[i] < 0:
                continue
            elif dp[j-1][l-y[i]] == -1:
                continue
            else:
                dp[j][l] = max(dp[j][l], dp[j-1][l-y[i]]+x[i])
ans = 0
for i in range(1,MAXY+1,1):
    #print(dp[k][i])
    ans = max(ans, min(dp[k][i],i))
print(ans)
