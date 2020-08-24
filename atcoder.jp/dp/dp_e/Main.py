N, W = map(int, input().split())
w = [0] * (N+1)
v = [0] * (N+1)
for i in range(1, N + 1):
    w[i], v[i] = map(int, input().split())

dp = [[1000000001] * 100001 for _ in range(N + 1)] #i番目までで価値がj以上となる最小重さ
dp[0][0] = 100000001
ans = 0
for i in range(1, N + 1):
    for j in range(1, 100001):
        if v[i] < j:
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i])
        else:
            dp[i][j] = min(dp[i - 1][j], w[i])


for i in range(100001):
    if dp[N][i] <= W:
        ans = i
print(ans)