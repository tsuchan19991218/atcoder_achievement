K, A, B = map(int, input().split())
if B - A <= 2 or K - A < 1:
    ans = 1 + K
else:
    ans = 1
    K -= A - 1
    ans += A - 1
    if K % 2 == 0:
        ans += (B - A) * (K // 2)
    else:
        K -= 1
        ans += 1 + (B - A) * (K // 2)
print(ans)