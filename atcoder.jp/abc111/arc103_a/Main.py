from collections import Counter
n = int(input())
v = list(map(int, input().split()))
kisu = []
gusu = []
for i in range(n):
    if i % 2 == 0:
        kisu.append(v[i])
    else:
        gusu.append(v[i])
k = sorted(Counter(kisu).items(), key=lambda x: x[1], reverse=True)
g = sorted(Counter(gusu).items(), key=lambda x: x[1], reverse=True)
ans1 = 0
ans2 = 0
#print(k, g)
if k[0][0] == g[0][0]:
    if k[0][1] > g[0][1]:
        ans1 = (n//2) - k[0][1]
        if len(g) < 2:
            ans2 = n // 2
        else:
            ans2 = (n//2) - g[1][1]
    elif k[0][1] < g[0][1]:
        ans1 = (n//2) - g[0][1]
        if len(k) < 2:
            ans2 = n // 2
        else:
            ans2 = (n//2) - k[1][1]
    else:
        if len(k) < 2:
            ans2 = n // 2
        else:
            if k[1][1] == g[1][1]:
                ans1 = (n // 2) - k[0][1]
                ans2 = (n // 2) - g[1][1]
            elif k[1][1] > g[1][1]:
                ans1 = (n // 2) - k[1][1]
                ans2 = (n // 2) - g[0][1]
            else:
                ans1 = (n // 2) - k[0][1]
                ans2 = (n // 2) - g[1][1]
else:
    ans1 = (n // 2) - k[0][1]
    ans2 = (n // 2) - g[0][1]
print(ans1 + ans2)


