import math
from functools import lru_cache
from operator import mul
from functools import reduce


def cmb(n, r, mod):
    numerator = reduce(lambda x, y: x * y % mod, [n - r + k + 1 for k in range(r)])
    denominator = reduce(lambda x, y: x * y % mod, [k + 1 for k in range(r)])
    return numerator * pow(denominator, mod - 2, mod) % mod


x, y = map(int, input().split())
mod = 1000000007
cnt = (x + y) // 3
if (x + y) % 3 != 0:
    print(0)
    exit()
m = min(x, y)
num_2 = m - cnt
num_1 = cnt - num_2
ans = cmb(cnt, num_1, mod)
print(ans)

