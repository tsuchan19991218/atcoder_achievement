from collections import deque
n, m, k = map(int, input().split())
ans = []
for i in range(0, n + 1):
    for j in range(0, m + 1):
        cnt = (i * m) + (j * n) - 2 * (i * j)
        # print(i, j, cnt)
        ans.append(cnt)
if k in ans:
    print("Yes")
else:
    print("No")