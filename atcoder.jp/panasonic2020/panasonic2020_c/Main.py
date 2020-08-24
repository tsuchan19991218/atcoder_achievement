import math
a, b, c = map(int, input().split())
#_ab = math.sqrt(a * b)
#print(_ab)
if c - (a + b) < 0:
    print("No")
else:
    #right = math.pow(c - (a + b), 2)
    right = (c - (a + b)) ** 2
    left = 4 * a * b
    if left < right:
        print("Yes")
    else:
        print("No")
