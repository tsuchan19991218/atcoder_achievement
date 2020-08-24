n = int(input())
a = list(map(int, input().split()))
c_a = []
for i in range(n - 1):
    c_a.append(a[i + 1] - a[i])
#print(c_a)
b = 0 # 0 ~ n-2
e = 0 # 0 ~ n-1
ans = n
for b in range(n-1):
    e = max(e, b)
    while e < n-1:
        if c_a[e] <= 0:
            break
        e += 1
    ans += e - b

print(ans)