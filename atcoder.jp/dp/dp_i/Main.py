N = int(input())
p = [-1] + list(map(float, input().split()))
dp = [[1] * (N+1) for _ in range(N+1)] #i番目のコインまででj枚表が出る確率
dp[1][0] = 1 - p[1]
dp[1][1] = p[1]
for i in range(2, N + 1):
    for j in range(i + 1):
        if j == 0: #表０枚の確率
            dp[i][j] = dp[i-1][j] * (1 - p[i])
        elif j == i:
            dp[i][j] = dp[i-1][j-1] * p[i]
        else:
            dp[i][j] = dp[i-1][j] * (1 - p[i]) + dp[i-1][j-1] * p[i]
num = N // 2 + 1
ans = 0
while num <= N:
    ans += dp[N][num]
    num += 1
print(ans)