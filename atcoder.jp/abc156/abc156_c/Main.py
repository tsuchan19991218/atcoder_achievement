n = int(input())
x = list(map(int, input().split()))
ans = 1000000000
for p in range(min(x), max(x) + 1):
    a = 0
    for j in range(n):
        a += (p - x[j]) ** 2
    ans = min(a, ans)
print(ans)