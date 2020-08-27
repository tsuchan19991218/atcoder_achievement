from operator import mul
from functools import reduce


def combinations_count(n, r):
    r = min(r, n - r)
    numer = reduce(mul, range(n, n - r, -1), 1)
    denom = reduce(mul, range(1, r + 1), 1)
    return numer // denom


from collections import Counter
n, p = map(int, input().split())
a = list(map(int, input().split()))
a = sorted(list(map(lambda x: x % 2, a)))
a = Counter(a)
ans = 0
if p == 1:
    for i in range(1, a[1] + 1, 2):
        for j in range(a[0] + 1):
            ans += combinations_count(a[1], i) * combinations_count(a[0], j)
if p == 0:
    for i in range(0, a[1] + 1, 2):
        for j in range(a[0] + 1):
            ans += combinations_count(a[1], i) * combinations_count(a[0], j)
print(ans)