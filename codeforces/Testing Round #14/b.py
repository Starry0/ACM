[n,a,b] = [int(input()) for x in range(3)]
if 4*a+2*b <= n:
    print("1")
elif 2*a+b <= n or (3*a<=n and a+2*b<=n):
    print("2")
elif