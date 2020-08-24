H, W = map(int, input().split())
a = [list(input().split(" ")) for _ in range(H)]
dp = [[-1] * (W + 1) for _ in range(H + 1)]

#print(a)

def f(y, x):
    if dp[y][x] != -1:
        return dp[y][x]
    res = 0
    if x == W:
        res = f(y + 1, x)
    elif y == H:
        res = f(y, x + 1)
    else:
        res = f(y, x + 1) + f(y + 1, x)
    dp[y][x] = res
    return res


dp[H][W] = 1
for i in reversed(range(1, H + 1)):
    for j in reversed(range(1, W + 1)):
        #print(i, j)
        if a[i-1][0][j-1] == '#':
            dp[i][j] = 0
        else:
            f(i, j)
print(dp[1][1]%1000000007)
