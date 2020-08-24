import heapq
import math
N, M = map(int, input().split())
A = list(map(int, input().split()))

A = list(map(lambda x: x*(-1), A))
heapq.heapify(A)
ans = 0
while M > 0:
    max_price = heapq.heappop(A)

    max_price = math.ceil(max_price/2)
    M -= 1
    heapq.heappush(A, max_price)


A = list(map(lambda x: x*(-1), A))

for a in A:
    ans += a

print(ans)