from operator import mul
from functools import reduce
from collections import Counter


def combinations_count(n, r):
    r = min(r, n - r)
    numer = reduce(mul, range(n, n - r, -1), 1)
    denom = reduce(mul, range(1, r + 1), 1)
    return numer // denom


N = int(input())
A = list(map(int, input().split()))
dp = [0] * (N + 1)
ans = 0
l = Counter(A)
#print(l)
for sa in set(A):
    if l[sa] < 2:
        continue
    dp[sa] = combinations_count(l[sa], 2)
sum_dp = sum(dp)
#print(dp)
for a in A:
    ans = dp[a] * (l[a]-2)
    ans //= l[a]
    ans += sum_dp - dp[a]
    print(ans)