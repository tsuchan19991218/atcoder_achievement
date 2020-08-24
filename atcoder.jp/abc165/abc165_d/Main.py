A, B, N = map(int, input().split())
x = min(B-1, N)
ans = int(A*x / B)
print(ans)