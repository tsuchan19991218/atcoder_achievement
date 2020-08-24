N, X, T = map(int, input().split())
cnt = 0
ans = 0
while cnt < N:
    cnt += X
    ans += T
print(ans)