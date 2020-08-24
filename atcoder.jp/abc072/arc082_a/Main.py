N = int(input())
a = list(map(int, input().split()))
dp = [0] * 100001
for num in a:
    if num == 0:
        dp[num] += 1
        dp[num + 1] += 1
    elif a == 100000:
        dp[num] += 1
        dp[num - 1] += 1
    else:
        dp[num] += 1
        dp[num + 1] += 1
        dp[num - 1] += 1
print(max(dp))