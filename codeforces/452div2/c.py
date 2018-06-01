n = int(input())
a  = []
ans1 = ans2 = 0
for i in range(n,0,-1):
    if ans1 > ans2 :
        ans2 += i
    else :
        ans1 += i
        a.append(i)
print(abs(ans1-ans2))
print(len(a),*a)