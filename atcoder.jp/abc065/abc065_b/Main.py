N = int(input())
a = [0]
for _ in range(N):
    a.append(int(input()))
memo = [-1] + [1] + [0] * (N-1)
next = 1
cnt = 0
while True:
    cnt += 1
    next = a[next]
    if next == 2:
        print(cnt)
        break
    if memo[next] == 1:
        print(-1)
        break
    memo[next] = 1