import copy
mod = (10 ** 9) + 7
n = int(input())
a = list(map(int, input().split()))
M = sum(a)
a_sum = copy.copy(a)
for i in range(1, n):
    a_sum[i] = (a_sum[i - 1] + a_sum[i]) % mod
# print(a)
# print(a_sum)
ans = 0
for i in range(n):
    ans += a[i] * M
    ans -= a[i] * a_sum[i]
print(ans % mod)
