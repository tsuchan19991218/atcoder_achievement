import heapq
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

#条件を下回っている試験は絶対変更しなくてはいけない
ans = 0
rest = 0
ex = [] #分け与えることができる準備度の負の値
heapq.heapify(ex)
for i in range(N):
    if A[i] < B[i]:
        ans += 1
        rest += B[i] - A[i]
    else:
        heapq.heappush(ex, B[i] - A[i])

pre_len = len(ex)
#print(rest)
#print(ex)
while rest > 0:
    if len(ex) <= 0:
        print(-1)
        break
    minus_rest = heapq.heappop(ex)
    rest += minus_rest
else:
    print(ans + (pre_len - len(ex)))
