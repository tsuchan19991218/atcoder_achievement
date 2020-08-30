n = int(input())
cnt = [-1] + [1] + [2] * 10000000
for i in range(2, 10000002 // 2):
    for j in range(2 * i, 10000001, i):
        cnt[j] += 1
ans = 0
for i in range(1, n + 1):
    ans += i * cnt[i]
print(ans)