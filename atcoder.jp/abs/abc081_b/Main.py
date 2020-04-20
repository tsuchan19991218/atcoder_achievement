N = int(input())
A = list(map(int, input().split()))
ans = 0
while True:
    count = 0
    for a in A:
        if a % 2 == 0:
            count += 1
    if count == N:
        for i in range(N):
            A[i] /= 2
    else:
        break
    ans += 1

print(ans)
