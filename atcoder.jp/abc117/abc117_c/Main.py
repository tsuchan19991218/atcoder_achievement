import heapq
N, M = map(int, input().split())
if N >= M:
    print(0)
    exit()
X = list(map(int, input().split()))
X.sort(reverse=True)
dist = []
for i in range(1, M):
    dist.append(X[i] - X[i - 1])
dist = list(map(lambda x: (-1) * abs(x), dist))
heapq.heapify(dist)
#print(dist)
for _ in range(N - 1):
    heapq.heappop(dist)
ans = -1 * sum(dist)
print(ans)

