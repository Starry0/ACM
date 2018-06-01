#python3
k, n, m = map(int,input().split())
x, y = [],[]
for i in range(k):
    q, p = map(int, input().split())
    x.append(min(q, p))
    y.append(max(q, p))
MAX = 0
for i in range(k):
    for j in range(i+1,k):
        ok = False
        if x[i] + x[j] <= n and y[i] <= m and y[j] <= m:
            ok = True
        elif x[i] + y[j] <= n and y[i] <= m and x[j] <= m:
            ok = True
        elif y[i] + y[j] <= m and x[i] <= n and x[j] <= n:
            ok = True
        elif y[i] + x[j] <= m and x[i] <= n and y[j] <= n:
            ok = True
        elif y[i] + y[j] <= n and x[i] <= m and x[j] <= m:
            ok = True
        elif y[i] + x[j] <= n and x[i] <= m and y[j] <= m:
            ok = True
        elif x[i] + x[j] <= m and y[i] <= n and y[j] <= n:
            ok = True
        elif x[i] + y[j] <= m and y[i] <= n and x[j] <= n:
            ok = True
        if ok:
            MAX = max(MAX, x[i]*y[i] + x[j]*y[j])
print(MAX)
