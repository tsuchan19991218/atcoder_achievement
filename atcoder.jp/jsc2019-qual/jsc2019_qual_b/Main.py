N, K = map(int, input().split())
A = list(map(int, input().split()))
before = [0] * N
after = [0] * N
for i in range(N):
    for j in range(N):
        if i == j:
            continue
        if i < j:
            if A[i] > A[j]:
                after[i] += 1
        elif i > j:
            if A[i] > A[j]:
                before[i] += 1
sum_after = (sum(after) * (K * (K + 1)) // 2) % ((10 ** 9) + 7)
K -= 1
sum_before = (sum(before) * (K * (K + 1)) // 2) % ((10 ** 9) + 7)
ans = sum_after + sum_before
ans %= ((10 ** 9) + 7)
#print(after, before)
#print(sum_after, sum_before)
print(ans)