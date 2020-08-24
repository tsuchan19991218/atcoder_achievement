import heapq
from collections import Counter
N, K = map(int, input().split())
A = list(map(int, input().split()))
l = Counter(A)
#print(l)
dif = len(l) - K
if dif <= 0:
    print(0)
    exit()
l = list(l.values())
heapq.heapify(l)
#print(l)
ans = 0
for i in range(dif):
    ans += heapq.heappop(l)
print(ans)