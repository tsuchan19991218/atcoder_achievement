H, W = map(int, input().split())
s = []
for _ in range(H):
    s.append(input())
dx = (0, 1, 0, -1)
dy = (1, 0, -1, 0)

for i in range(H):
    for j in range(W):
        if s[i][j] == "#":
            for d in range(4):
                ni = i + dy[d]
                nj = j + dx[d]
                if ni < 0 or ni >= H:
                    continue
                if nj < 0 or nj >= W:
                    continue
                if s[ni][nj] == "#":
                    break
            else:
                break
            continue
    else:
        continue
    print("No")
    break
else:
    print("Yes")

