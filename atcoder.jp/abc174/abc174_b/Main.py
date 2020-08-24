N, D = map(int, input().split())
XY = [[] for _ in range(N)]
X = [0] * N
Y = [0] * N
for i in range(N):
    XY[i] = list(map(int, input().split()))
    X[i] = XY[i][0]
    Y[i] = XY[i][1]

ans = 0
for i in range(N):
    if (X[i]**2 + Y[i]**2) ** 0.5 <= D:
        ans += 1
print(ans)
