a,b,c = map(int, input().strip().split())
a = str(a/b)
print(a)
for i in range(1,len(a)):
    print(type(int(str[i])), type(c))
'''   if(int(str[i]) == c):
	    print(i-1)
	    break
'''
print('-1')