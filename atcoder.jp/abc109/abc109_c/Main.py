import math
N, X = map(int, input().split())
x = list(map(int, input().split()))
x = list(map(lambda x: x - X, x))
ans = min(list(map(lambda x: abs(x), x)))
for num in x:
    ans = math.gcd(ans, num)
print(ans)