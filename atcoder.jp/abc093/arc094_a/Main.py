from math import ceil
a = list(map(int, input().split()))
a.sort()
kisu_cnt = 0
ans = 0
for _a in a:
    if _a % 2 == 1:
        kisu_cnt += 1
if kisu_cnt == 3 or kisu_cnt == 0:
    ans += (a[-1] - a[1]) // 2
    ans += (a[-1] - a[0]) // 2
    print(ans)
    exit()
else:
    if kisu_cnt == 1:
        for i in range(3):
            if a[i] % 2 == 0:
                a[i] += 1
    else:
        for i in range(3):
            if a[i] % 2 == 1:
                a[i] += 1
a.sort()
ans += 1
ans += (a[-1] - a[1]) // 2
ans += (a[-1] - a[0]) // 2
print(ans)




