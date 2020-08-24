import sys
sys.setrecursionlimit(2000)

N, M = map(int, input().split())
x = [0] * M
y = [0] * M
G = [[] for _ in range(N + 1)]
for i in range(M):
    X, Y = map(int, input().split())
    x[i] = X
    y[i] = Y
    G[X] += [Y]

dp = [-1] * (N + 1)


def f(n):
    if dp[n] != -1:
        return dp[n]
    res = 0
    for m in G[n]:
        res = max(res, f(m) + 1)
    dp[n] = res
    return res


for i in range(1, N + 1):
    f(i)
print(max(dp))