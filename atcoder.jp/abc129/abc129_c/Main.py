n, m = map(int, input().split())
a = [True] * (n + 1)
for _ in range(m):
    a[int(input())] = False
dp = [0] * (n + 1)
dp[0] = 1
for i in range(n):
    if a[i + 1]:
        dp[i + 1] += dp[i]
    if i + 2 < n + 1:
        if a[i + 2]:
            dp[i + 2] += dp[i]
print(dp[n] % 1000000007)