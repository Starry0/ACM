import math
n = int(input())
a = list(map(int, input().split()))
a.sort()
st = []
cnt1 = cnt2 = cnt3 = 0
for x in a:
    tmp = int(math.sqrt(x))
    if x == 0:
        cnt3 += 1
    if tmp*tmp == x:
        cnt1 += 1
    else :
        st.append(x)
        cnt2 += 1
ans = 0
if cnt1 > cnt2:
    cnt1 -= cnt3
    if cnt1 >= (n/2-cnt2):
        print(int(n/2-cnt2))
    else:
        print(int(cnt1+2*(n/2-cnt2-cnt1)))
elif cnt1 < cnt2:
    vs = []
    for x in st:
        tmp = int(math.sqrt(x))
        MIN = min(x-tmp*tmp,(tmp+1)*(tmp+1)-x)
        vs.append(MIN)
    vs.sort()
    for i in range(int((cnt2-cnt1)/2)):
        ans += vs[i]
    print(ans)
else :
    print('0')
