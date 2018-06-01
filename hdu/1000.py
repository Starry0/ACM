#python2
while True:
    try:
        a, b = map(int, raw_input().strip().split())
        print(a+b)
    except EOFError:
        break
