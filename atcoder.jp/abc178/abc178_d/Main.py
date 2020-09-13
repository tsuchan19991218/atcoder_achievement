from functools import lru_cache
import sys

sys.setrecursionlimit(100000)

s = int(input())
# for cnt_5 in range(s // 5):
#     for cnt_4 in range((s - (cnt_5 * 5)) // 4):
#         rest = s - (cnt_5 * 5 + cnt_4 * 4)
#         if rest % 3 != 0:
#             continue
#         cnt_3 = rest // 3
@lru_cache(maxsize=2000)
def f(n):
    if n < 3:
        return 0
    if n >= 3 and n <= 5:
        return 1

    ans = 0
    for i in range(3, (n-1) // 2 + 1):
        ans += f(i) + f(n - i)
    if n % 2 == 0:
        ans += f(n // 2)
    ans += 1
    return ans % 1000000007

print(f(s))



