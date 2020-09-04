n = int(input())
F = []
P = []
for _ in range(n):
    F.append(list(map(int, input().split())))
for _ in range(n):
    P.append(list(map(int, input().split())))
ans = -1000000000
for pattern in range(1, 2 ** 10):
    _ans = 0
    for shop in range(n):
        match_cnt = 0
        for i in range(10):
            if F[shop][i] == 0:
                continue
            if (pattern >> i) & 1:
                match_cnt += 1
        _ans += P[shop][match_cnt]
    ans = max(ans, _ans)
print(ans)
