n,d = map(int,input().split())
s = input()
dp = [100000]*n
dp[0] = 0
for i in range(n):
    if s[i] == '1':
        for j in range(max(0,i-d),i):
            dp[i] = min(dp[i],dp[j]+1)
print([-1,dp[n-1]][dp[n-1]!=100000])