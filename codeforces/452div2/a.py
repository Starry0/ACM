n = int(input())
li = list(map(int,input().split()))
a = li.count(1)
b = li.count(2)
print(min(a,b)+int((a-min(a,b))/3))