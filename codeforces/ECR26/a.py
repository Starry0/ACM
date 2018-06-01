#python2
'''
n, a = raw_input(), raw_input().split()
k = 0
for i in a:
    ans = 0
    for c in i:
        if c.isupper():
            ans += 1
    k = max(k, ans)
print k
'''
#python3
n, a = input(), input().split()
k = 0
for i in a:
    ans = 0
    for c in i:
        if c.isupper():
            ans += 1
    k = max(k, ans)
print(k)
