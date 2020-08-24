s = input()
t = input()

dp = [[0] * len(t) for _ in range(len(s))]
for i in range(0, len(s)):
    for j in range(0, len(t)):
        if s[i] == t[j]:
            if i == 0 or j == 0:
                dp[i][j] = 1
            else:
                dp[i][j] = dp[i-1][j-1] + 1
        else:
            if i == 0:
                dp[i][j] = dp[i][j-1]
            elif j == 0:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])


ans = " "
i = len(s) - 1
j = len(t) - 1
while i >= 0 and j >= 0:
    if s[i] == t[j]:
        ans = s[i] + ans
        i -= 1
        j -= 1
    elif i == 0:
        if dp[i][j] == 1:
            ans = s[i] + ans
        break
    elif j == 0:
        if dp[i][j] == 1:
            ans = t[j] + ans
        break
    else:
        if dp[i-1][j] == dp[i][j]:
            i -= 1
        elif dp[i][j-1] == dp[i][j]:
            j -= 1
        else:
            j -= 1
            i -= 1
print(ans)