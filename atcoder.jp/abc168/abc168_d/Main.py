from collections import deque
n, m = map(int, input().split())
INF = 1000000
to_room = [[] for _ in range(n + 1)]
for i in range(m):
    a, b = map(int, input().split())
    to_room[a].append(b)
    to_room[b].append(a)
dp = [INF] * (n + 1)
dp[1] = 0
seen_room = deque()
seen_room.append(1)
ans = [0] * (n + 1)
while seen_room:
    v = seen_room.popleft()
    for next in to_room[v]:
        if dp[next] <= dp[v] + 1:
            continue
        dp[next] = dp[v] + 1
        ans[next] = v
        seen_room.append(next)
#     print(seen_room)
# print(to_room)
# print(dp)
if 0 in ans[2:]:
    print("No")
else:
    print("Yes")
    for a in ans[2:]:
        print(a)

