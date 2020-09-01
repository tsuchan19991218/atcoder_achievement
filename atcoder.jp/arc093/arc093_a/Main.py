n = int(input())
a = list(map(int, input().split()))
# tobitobi[i] -> distance [i - 1] to [i + 1]
tobitobi = [0] * n
for i in range(1, n - 1):
    tobitobi[i] = abs(a[i - 1] - a[i + 1])
sum_of_dis = abs(a[0]) + abs(a[n - 1])
for i in range(1, n):
    sum_of_dis += abs(a[i] - a[i - 1])
ans = [0] * (n)
for i in range(n):
    if i == 0:
        ans[i] = sum_of_dis - abs(a[i]) - abs(a[i] - a[i + 1]) + abs(a[i + 1])
    elif i == n - 1:
        ans[i] = sum_of_dis - abs(a[i]) - abs(a[i] - a[i - 1]) + abs(a[i - 1])
    else:
        ans[i] = sum_of_dis - (abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1])) + tobitobi[i]
for ANS in ans:
    print(ANS)
