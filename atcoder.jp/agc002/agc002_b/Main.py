N, M = map(int, input().split())
x = [0]
y = [0]
memo = [1] * (N + 1) #各箱の中のボールの数
flag = [0] * (N + 1) #赤ボールがある可能性
for _ in range(M):
    _x, _y = map(int, input().split())
    x.append(_x)
    y.append(_y)

flag[1] = 1
for i in range(1, M + 1):
    if memo[x[i]] == 0: #移動するボール無し
        continue
    memo[x[i]] -= 1
    memo[y[i]] += 1
    if flag[x[i]] == 1:
        flag[y[i]] = 1
    if memo[x[i]] == 0:
        flag[x[i]] = 0

ans = 0
for i in range(1, N + 1):
    if memo[i] <= 0:
        continue
    if flag[i] == 1:
        ans += 1
#print(memo)
#print(flag)
print(ans)
