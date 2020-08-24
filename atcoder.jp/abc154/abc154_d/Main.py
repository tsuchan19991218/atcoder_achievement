N, K = map(int, input().split())
p = list(map(int, input().split()))
p = list(map(lambda x: (x + 1)/2, p))
ans = 0
for i in range(1, len(p)):
    p[i] += p[i - 1]
for i in range(K - 1, len(p)):
    if i == K - 1:
        ans = p[i]
    else:
        ans = max(ans, p[i] - p[i - K])
print(ans)