N, X, Y = map(int, input().split())
ans = [0] * N
for i in range(1, N + 1):
    for j in range(i + 1, N + 1):
        dist = min(abs(i - j), abs(X - i) + 1 + abs(Y - j), abs(Y - i) + 1 + abs(X - j))
        ans[dist] += 1
for a in ans[1:]:
    print(a)
