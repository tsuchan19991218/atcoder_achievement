A, B, C = map(int, input().split())
dp = [-1] * 100
_A = A
while True:
    if A % B == C:
        print("YES")
        break
    if dp[A%B] != -1:
        print("NO")
        break
    dp[A%B] = 1
    A = A % B + _A
    #print(A)

