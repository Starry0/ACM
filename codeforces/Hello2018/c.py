n, L = map(int, input().split())
c = list(map(int, input().split()))
best = [(c[i]/(1<<i),i) for i in range(0, n)]
best.sort()

cost = 0
costs = [0]*n
print(best)
for i in range(0,n):
    a, b = best[i]
    q = L//(1<<b)
    L -= q * (1<<b)
    cost += q * c[b]
    print(cost,q)
    if L > 0:
        costs[i] = cost + c[b]
    else:
        costs[i] = cost
    print(costs[i], cost,L)
print(min(min(costs), cost))