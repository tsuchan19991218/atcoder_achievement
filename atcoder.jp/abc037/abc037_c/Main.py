n, k = map(int, input().split())
a = [0] + list(map(int, input().split()))
for i in range(1, len(a)):
    a[i] += a[i - 1]

ans = 0
for i in range(k, len(a)):
    ans += a[i] - a[i - k]
print(ans)