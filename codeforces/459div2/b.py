n,m = map(int,input().split())
di = {}
for i in range(n+m):
    s,s1 = input().split()
    if s1[-1] == ';':
        s1 = s1[:-1]
    if s1 in di:
        print(s+' '+s1+'; #'+di[s1])
    else:
        di[s1] = s;