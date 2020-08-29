from collections import deque
n, m = map(int, input().split())
fiend_memo = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    fiend_memo[a].append(b)
    fiend_memo[b].append(a)
#print(fiend_memo)
make_group = []
ans = 0
d = deque()
d.append(1)
seen = {}
# seen[1] = 1
for person in range(1, n + 1):
    cnt = 0
    if person not in seen.keys():
        d.append(person)
        seen[person] = 1
        cnt += 1
    while d:
        now_person = d.popleft()
        for next_person in fiend_memo[now_person]:
            if next_person not in seen.keys():
                d.append(next_person)
                seen[next_person] = 1
                cnt += 1
    ans = max(ans, cnt)
print(ans)