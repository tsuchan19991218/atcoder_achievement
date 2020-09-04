n = int(input())
a = list(map(int, input().split()))
if sum(a) % n != 0:
    print(-1)
    exit()
goal = sum(a) // n
for i in range(1, n):
    a[i] += a[i - 1]
cnt = 0
ans = 0
seen_sum = 0
for _a in a:
    if (_a - seen_sum) % (cnt + 1) == 0:
        if (_a - seen_sum) / (cnt + 1) == goal:
            ans += cnt
            cnt = 0
            seen_sum = _a
        else:
            cnt += 1
    else:
        cnt += 1
print(ans)