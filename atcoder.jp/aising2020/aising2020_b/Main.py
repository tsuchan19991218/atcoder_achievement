N = int(input())
A = list(map(int, input().split()))

ans = 0
for i in range(0, len(A), 2):
    if (A[i] % 2) == 1:
        ans += 1
print(ans)
