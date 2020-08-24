N = int(input())
A = list(map(int, input().split()))
up_or_down = 0
ans = 1
for i in range(len(A) - 1):
    if up_or_down == 0:
        up_or_down = A[i+1] - A[i]
    else:
        if up_or_down > 0 and A[i+1] - A[i] < 0:
            ans += 1
            up_or_down = 0
        elif up_or_down < 0 and A[i+1] - A[i] > 0:
            ans += 1
            up_or_down = 0
print(ans)