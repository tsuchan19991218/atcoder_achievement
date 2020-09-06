import sys
sys.setrecursionlimit(100000)

n, m = map(int, input().split())

def kaijo(n):
    if n == 1:
        return 1
    return n * kaijo(n - 1) % ((10 ** 9) + 7)


if abs(n - m) > 1:
    print(0)
    exit()
a = kaijo(n)
b = kaijo(m)

if n == m:
    print((a * b * 2) % ((10 ** 9) + 7))
else:
    print((a * b ) % ((10 ** 9) + 7))



