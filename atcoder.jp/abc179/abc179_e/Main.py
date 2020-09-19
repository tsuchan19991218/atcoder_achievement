from collections import deque

n, x, m = map(int, input().split())

A = [-1] * (10 ** 5)

i = 1
A[x] = i
sum = []
sum.append(0)
sum.append(x)
while i < n:
    i += 1
    x = (x * x) % m
    if A[x] != -1:
        break
    A[x] = i
    sum.append(sum[-1] + x)

if i == n:
    print(sum[n])
    exit()

pre_i = A[x]
dis = i - pre_i
cnt = (n + 1 - pre_i) // dis
div = (n + 1 - pre_i) % dis
ans = sum[pre_i - 1]
ans += (sum[i - 1] - sum[pre_i - 1]) * cnt
if div != 0:
    ans += sum[pre_i + div - 1] - sum[pre_i - 1]
print(ans)

