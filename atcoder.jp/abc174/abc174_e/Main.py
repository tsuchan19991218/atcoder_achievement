import math
N, K = map(int, input().split())
A = list(map(int, input().split()))
start = 0
end = max(A)
ans = abs(end + start) // 2 + 1
while abs(start - end) > 1:
    ans = abs(end + start) // 2
    cnt = 0
    for i in range(N):
        cnt += math.floor(A[i]/ans - 0.0000000001)
        if cnt > K: #ダメだったら
            start = ans
            break
    else: #オッケーだったら
        end = ans
        continue

cnt = 0
for i in range(N):
    cnt += math.floor((A[i] / ans) - 0.000000000001)

if cnt > K:  # ダメだったら
    print(ans + 1)
else:  # オッケーだったら
    print(ans)
