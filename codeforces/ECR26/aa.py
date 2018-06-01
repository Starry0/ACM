R=lambda:map(int,raw_input().split())
n,a,b=R()
def go(x,y,u,v):
  if x>a or y>b or u>a or v>b:
    return 0
  return x*y+u*v if x+u<=a or y+v<=b else 0
t=[R() for _ in xrange(n)]
s=0
for i in range(n):
  x,y=t[i]
  for j in range(i+1,n):
    u,v=t[j]
    s=max(s,go(x,y,u,v))
    s=max(s,go(y,x,u,v))
    s=max(s,go(x,y,v,u))
    s=max(s,go(y,x,v,u))
print s
