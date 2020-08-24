H, W = map(int, input().split())
S = []
for _ in range(H):
    S.append(input())
ans = [[0] * W for _ in range(H)]
for y in range(H):
    for x in range(W):
        if S[y][x] == "#":
            ans[y][x] = "#"
            if not (y == H-1 or x == W-1):
                if S[y+1][x+1] != "#":
                    ans[y+1][x+1] += 1
            if not y == H - 1:
                if S[y+1][x] != "#":
                    ans[y+1][x] += 1
            if not x == W - 1:
                if S[y][x+1] != "#":
                    ans[y][x+1] += 1
            if not (y == H - 1 or x == 0):
                if S[y+1][x-1] != "#":
                    ans[y+1][x-1] += 1
            if not (y == 0 or x == W - 1):
                if S[y-1][x+1] != "#":
                    ans[y-1][x+1] += 1
            if not x == 0:
                if S[y][x-1] != "#":
                    ans[y][x-1] += 1
            if not y == 0:
                if S[y-1][x] != "#":
                    ans[y-1][x] += 1
            if not (y == 0 or x == 0):
                if S[y-1][x-1] != "#":
                    ans[y-1][x-1] += 1

for i in range(H):
    print(''.join(map(str, ans[i])))

