a, b, c, x, y = map(int, input().split())
ans = 0
_ans = 2 * c * max(x, y)
if a + b >= 2 * c:
    ans = 2 * c * min(x, y)
else:
    ans += a * x + b * y
    print(min(ans, _ans))
    exit()
if y >= x:
    y -= x
    ans += b * y
else:
    x -= y
    ans += a * x
print(min(ans, _ans))