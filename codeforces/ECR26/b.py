N = 110
n, m = map(int, raw_input().strip().split())
def f(str):
    B,R,G = 0,0,0
    xb,yb,xr,yr,xg,yg = N,N,N,N,N,N
    xxb,yyb,xxr,yyr,xxg,yyg = -1,-1,-1,-1,-1,-1
    for i in range(n):
        for j in range(m):
            if str[i][j] == 'B':
                B+=1
                xb = min(xb,j)
                yb = min(yb,i)
                xxb = max(xxb,j)
                xxr = max(xxy,i)
            elif str[i][j] == 'R':
                R+=1
                xr = min(xr,j)
                yr = min(yr,i)
                xxr = max(xxr,j)
                xxr = max(xxr,i)
            elif str[i][j] == 'G':
                G+=1
                xg = min(xg,j)
                yg = min(yg,i)
                xxg = max(xxg,j)
                xxg = max(xxg,i)
    if B != 0 and B == R and R == G:
        if (yyb-yb+1)*(xxb-xb+1) == B and (yyr-yr+1)*(xxr-xr+1) == R and (yyg-yg+1)*(xxg-xg+1)==G:
            return True
        return False
    return False
str = [0]*n
for i in range(n):
    str[i] = list(raw_input().split())
if f(str):
    print"YES"
else:
    print"NO"
