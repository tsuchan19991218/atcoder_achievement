A = 0
B = 1
C = 2


N = int(input())
a = [0] * (N+1)
b = [0] * (N+1)
c = [0] * (N+1)
for i in range(1, N + 1):
    ABC = list(map(int, input().split()))
    a[i] = ABC[A]
    b[i] = ABC[B]
    c[i] = ABC[C]

dp = [[0] * 3 for i in range(N+1)]
dp[1][A] = a[1]
dp[1][B] = b[1]
dp[1][C] = c[1]

for i in range(1, N + 1):
    dp[i][A] = max(dp[i-1][B] + a[i], dp[i-1][C] + a[i])
    dp[i][B] = max(dp[i-1][A] + b[i], dp[i-1][C] + b[i])
    dp[i][C] = max(dp[i - 1][A] + c[i], dp[i - 1][B] + c[i])

print(max(dp[N][A], dp[N][B], dp[N][C]))

