a1 = '31 28 31 30 31 30 31 31 30 31 30 31 '
a2 = '31 29 31 30 31 30 31 31 30 31 30 31 '
s = a1 + a1 + a1 + a2 + a1 + a1
n = input()
ss = input().strip()
print(["NO",'YES'][ss in s])