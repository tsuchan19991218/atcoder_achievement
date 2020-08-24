K = int(input())
ans = 1
dp = [-1] * K
num = 7
while True:
    num = num % K
    if dp[num % K] != -1:
        print(-1)
        break
    elif num % K == 0:
        print(ans)
        break
    else:
        dp[num % K] = 1
    ans += 1
    num = num * 10 + 7

