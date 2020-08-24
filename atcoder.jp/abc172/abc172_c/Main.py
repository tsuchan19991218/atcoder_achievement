N, M, K = map(int, input().split())
A = [0] + list(map(int, input().split()))
B = [0] + list(map(int, input().split()))

for i in range(1, N + 1):
    A[i] += A[i-1]
for i in range(1, M + 1):
    B[i] += B[i-1]

ans = 0
b_cnt = M
for a_cnt in range(N + 1):
    if A[a_cnt] > K:
        continue
    while A[a_cnt] + B[b_cnt] > K:
        b_cnt -= 1
    ans = max(ans, a_cnt + b_cnt)

print(ans)