N = int(input())
A = list(map(int, input().split()))
mae_max = A[0]
ans = 0
for i in range(N):
    if mae_max > A[i]:
        ans += mae_max - A[i]
    else:
        mae_max = max(mae_max, A[i])
print(ans)