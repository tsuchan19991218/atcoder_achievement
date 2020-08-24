N, K = map(int, input().split())
N %= K
ans = 0
if abs(N - K) > N:
    ans = N
else:
   ans = abs(N-K)
print(ans)
