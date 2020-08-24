N, K = map(int, input().split())
H = list(map(int, input().split()))
H = [0] + H
dp = [0] * (N + 1)
dp[1] = 0
dp[2] = abs(H[2] - H[1])

for i in range(3, N+1):
    dp[i] = dp[i - 1] + abs(H[i] - H[i - 1])
    for j in range(1, K + 1):
        if i - j <= 0:
            break
        dp[i] = min(dp[i], dp[i - j] + abs(H[i] - H[i - j]))
print(dp[N])