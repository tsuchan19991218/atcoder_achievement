n, m = map(int, input().split())
Q = []
for _ in range(m):
    q = list(map(int, input().split()))
    Q.append(q)
p = list(map(int, input().split()))
ans = 0
#　全てのスイッチパターンを列挙
for pattern in range(2 ** n):
    #p = bin(p)
    for i in range(len(Q)):
        on_cnt = 0
        for j in range(1, len(Q[i])):
            if ((pattern >> (Q[i][j] - 1)) & 1):
                on_cnt += 1
        if on_cnt % 2 != p[i]:
            break
    else:
        ans += 1
print(ans)
