from collections import Counter
from operator import mul
from functools import reduce


n = int(input())
A = list(map(int, input().split()))
cnt_a = Counter(A)
memo = [1] * 1000001
for a in A:
    memo[a] = 1
A.sort()
a_max = max(A)
for a in A:
    if not memo[a]:
        continue
    for i in range(a * 2, a_max + 1, a):
        memo[i] = -1
for l in cnt_a.keys():
    if cnt_a[l] >= 2:
        memo[l] = "daburi"
ans = 0
for a in A:
    if memo[a] == 1:
        ans += 1
print(ans)
