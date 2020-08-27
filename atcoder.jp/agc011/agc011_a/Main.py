n, c, k = map(int, input().split())
t = []
for _ in range(n):
    t.append(int(input()))
ans = 0
time_cnt = 0
mem_cnt = 1
t.sort()
for i in range(n - 1):
    time_cnt += t[i + 1] - t[i]
    mem_cnt += 1
    # print(time_cnt)
    if time_cnt > k or mem_cnt > c:
        time_cnt = 0
        mem_cnt = 1
        ans += 1
if mem_cnt == 0:
    ans += 1
elif mem_cnt > 0:
    ans += 1
print(ans)

