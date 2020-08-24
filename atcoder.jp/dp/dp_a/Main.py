N = int(input())
H = list(map(int, input().split()))
H = [0] + H
dp = [0] * (N + 1)
dp[1] = 0
dp[2] = abs(H[2] - H[1])

for i in range(3, N+1):
    dp[i] = min(dp[i-2] + abs(H[i-2] - H[i]), dp[i-1] + abs(H[i-1] - H[i]))

print(dp[N])