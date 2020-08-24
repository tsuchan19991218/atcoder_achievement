N, M, X = map(int, input().split())
C = [0] * N
A = [[] for _ in range(N)]
for i in range(N):
    c_a = list(map(int, input().split()))
    C[i] = c_a[0]
    A[i] = list(c_a[1:])

INF = 9999999999
ans = INF
for i in range(2 ** N):
    price = []
    rikaido = [0] * M
    for j in range(N):
        if (i >> j) & 1:
            price.append(C[j])
            for k in range(M):
                rikaido[k] += A[j][k]
    for l in range(M):
        if rikaido[l] < X:
            break
    else:
        ans = min(ans, sum(price))

if ans == INF:
    ans = -1
print(ans)