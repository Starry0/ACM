a = []

def isPrime(x):
	for i in range(2,x-1):
		if x%i == 0:
			return False
	return True
for i in range(2,300):
	if isPrime(i):
		a.append(i)

mp = {}
p = q = s = 1
mp[1] = (p,q)

def gcd(a, b):
	if b == 0: return a
	return gcd(b, a%b)
def ok(p, q, x):
	p = x*p
	q = (x+1)*q
	tmp = gcd(p, q)
	p //= tmp
	q //= tmp
	return p, q
for x in a:
	s *= x
	p,q = ok(p,q,x)
	mp[s] = (p,q)

t = int(input())
for i in range(t):
	n = int(input())
	p = q = 1
	for s in mp:
		if n >= s:
			(p,q) = mp[s]
	print("%s/%s"%(p,q))
