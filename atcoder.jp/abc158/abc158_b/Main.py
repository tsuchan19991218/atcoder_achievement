n, a, b = map(int, input().split())
mod = a + b
ans = 0
ans += (n // mod) * a
n -= mod * (n // mod)
ans += min(a, n)
print(ans)