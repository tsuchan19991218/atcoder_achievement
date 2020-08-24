from pprint import pprint
H, W = map(int, input().split())
s = ["-1"]
dp = [[1000] * (W + 1) for _ in range(H + 1)]
for _ in range(H):
    s.append(input())
s = list(map(lambda x: " " + x, s))
for y in range(1, H + 1):
    for x in range(1, W + 1):
        if y == 1 and x == 1:
            if s[y][x] == "#":
                dp[y][x] = 1
            else:
                dp[y][x] = 0
            continue
        if x == 1:
            if s[y][x] == "#":
                if s[y - 1][x] == "#":
                    dp[y][x] = dp[y - 1][x]
                else:
                    dp[y][x] = dp[y - 1][x] + 1
            else:
                dp[y][x] = dp[y - 1][x]
        elif y == 1:
            if s[y][x] == "#":
                if s[y][x - 1] == "#":
                    dp[y][x] = dp[y][x - 1]
                else:
                    dp[y][x] = dp[y][x - 1] + 1
            else:
                dp[y][x] = dp[y][x - 1]
        else:
            if s[y][x] == "#":
                if s[y][x - 1] == "#":
                    dp[y][x] = dp[y][x - 1]
                if s[y - 1][x] == "#":
                    dp[y][x] = min(dp[y][x], dp[y - 1][x])
                if s[y][x - 1] != "#" and s[y - 1][x] != "#":
                    dp[y][x] = min(dp[y][x - 1], dp[y - 1][x]) + 1
            else:
                dp[y][x] = min(dp[y][x - 1], dp[y - 1][x])
#pprint(dp)
print(dp[H][W])


