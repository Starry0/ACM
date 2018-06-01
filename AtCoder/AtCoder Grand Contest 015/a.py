n,a,b = map(int, raw_input().strip().split())
if(a > b or (a < b and n == 1)):
    print(0)
elif(a == b or (a < b and n == 2)):
    print(1)
elif(a < b and n >= 2):
    print((n-1)*b+a-()(n-1)*a-b))
