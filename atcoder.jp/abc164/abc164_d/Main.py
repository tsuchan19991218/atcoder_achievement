from collections import Counter


from operator import mul
from functools import reduce

def combinations_count(n, r):
    r = min(r, n - r)
    numer = reduce(mul, range(n, n - r, -1), 1)
    denom = reduce(mul, range(1, r + 1), 1)
    return numer // denom


S = input()
div = []
s = 0
kurai = 1
for i in range(len(S) - 1, -1, -1):
    # s += int(S[i]) * ((10 ** (len(S) - 1 - i)) % 2019)
    # s %= 2019
    if i == len(S) - 1:
        s += int(S[i]) * kurai
    else:
        s += int(S[i]) * kurai
    kurai *= 10
    kurai %= 2019
    s %= 2019
    div.append(s)
div_cnt = Counter(div)
ans = div_cnt[0]
for l in div_cnt.values():
    if l >= 2:
        ans += l * (l-1) // 2
print(ans)
