from collections import Counter
N = int(input())
D = list(map(int, input().split()))
if D[0] != 0:
    print(0)
    exit()
D = Counter(D)
if 0 not in D.keys():
    print(0)
    exit()
if D[0] > 1:
    print(0)
    exit()
max_key = max(D.keys())
cnt = [0] * (max_key + 1)
for i in range(0, max_key + 1):
    cnt[i] = D[i]
ans = 1
for i in range(1, len(cnt)):
    ans *= (cnt[i-1] ** cnt[i])
    ans %= 998244353
print(ans % 998244353)