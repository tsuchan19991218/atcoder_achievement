import math
a, b, x = map(int, input().split())
water_h = x / (a * a)
rest_b = b - water_h
if x > (a * a * b) / 2:
    ans = math.degrees(math.atan(rest_b/(a / 2)))
else:
    x /= a
    water_h = (2 * x) / b
    ans = math.degrees(math.atan(b / water_h))
print(ans)