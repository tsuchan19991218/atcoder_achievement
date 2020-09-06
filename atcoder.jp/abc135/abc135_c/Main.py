n = int(input())
a = list(map(int, input().split()))
sum_a = sum(a)
b = list(map(int, input().split()))
for i in range(n):
    if b[i] >= a[i]:
        b[i] -= a[i]
        a[i] = 0
    else:
        a[i] -= b[i]
        continue
    a[i + 1] -= b[i]
    if a[i + 1] < 0:
        a[i + 1] = 0

if a[-1] < 0:
    a[-1] = 0
print(sum_a - sum(a))