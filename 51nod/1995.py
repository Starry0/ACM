t = int(input())
for i in range(t):
    x,y = map(int, input().split())
    if (x==1 or x==3 ) and (y==1 or y == 4):
        print("Win\n6")
    elif x==2 and (y==1 or y==4):
        print("Equal\n0")
    else:
        print("Win\n4")