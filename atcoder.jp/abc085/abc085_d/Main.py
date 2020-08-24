N, H = map(int, input().split())
a = [0] * N
b = [0] * N
for i in range(N):
    a[i], b[i] = map(int, input().split())
max_a = max(a)
sorted_b = sorted(b, reverse=True)
index = 0
for num in sorted_b:
    if num < max_a:
        break
    index += 1
todome_point = sum(sorted_b[:index])
ans = 0
#先に投げる方を考える
sorted_b = sorted_b[:index]
for num in sorted_b:
    H -= num
    ans += 1
    if H <= 0:
        break
#殴り回数
if H > 0:
    ans += H // max_a
    if H % max_a != 0:
        ans += 1
print(ans)