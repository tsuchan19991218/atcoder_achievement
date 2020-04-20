def cal(N):
    ans = 0
    while True:
        ans += N % 10
        if N < 10:
            break
        else:
            N /= 10
            N = int(N)
    return ans


N, A, B = map(int, input().split())
ans = 0

for i in range(N + 1):
    if cal(i) >= A and cal(i) <= B:
        ans += i

print(ans)