n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
dif = 1000000000
best = a[0] // 2
ans = 0
for i in range(1, n):
    new_dif = abs(best - a[i])
    if dif <= new_dif:
        ans = a[i - 1]
        break
    dif = new_dif
else:
    print(a[0], a[1])
    exit()
print(a[0], ans)

