l = int(input())
dp = [0] * 205
dp[12] = 1
for i in range(13, 205):
    dp[i] = (dp[i - 1] * (i - 1)) // (i - 12)
print(int(dp[l]))