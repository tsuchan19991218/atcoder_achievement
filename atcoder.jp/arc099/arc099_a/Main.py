N, K = map(int, input().split())
A = [0] + list(map(int, input().split()))
index_1 = A.index(1)
N -= K
ans = 1
while N > 0:
    N -= K - 1
    ans += 1
print(ans)
