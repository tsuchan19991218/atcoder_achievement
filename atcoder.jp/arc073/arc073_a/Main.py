N, T = map(int, input().split())
t = list(map(int, input().split()))
ans = N * T
dt = []
for i in range(1, N):
    dt.append(t[i] - t[i-1])
for d_t in dt:
    if d_t < T:
        los = T - d_t
        ans -= los
print(ans)
