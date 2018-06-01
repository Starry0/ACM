t = int(input())
for i in range(t):
    n,k = input().split()
    for j in range(int(k)):
        l = list(n)
        l.sort()
        n = "".join(l)
        n = str(abs(int(n) - int(n[::-1])))
    print(n)
