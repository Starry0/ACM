n = int(input())

vis = []
a ,b = 1, 1
for i in range(55):
    vis.append(b)
    a,b = b,a+b
s = ""
for i in range(n):
    if vis.count(i+1):
        s += 'O'
    else :
        s += 'o'
print(s)