MAXN = 10 ** 6
n = int(input())
dp = [0] * (MAXN + 1)
dp[3] = 1

for i in range(4, MAXN + 1):
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
    dp[i] %= 10007

print(dp[n])

