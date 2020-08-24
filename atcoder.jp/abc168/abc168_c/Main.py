import math
A, B, H, M = map(int, input().split())
H += M/60
kakudo = 2 * math.pi * ((H/12) - (M/60))

ans = A**2 + B**2 - (2*A*B*math.cos(kakudo))
ans = math.sqrt(ans)

print(ans)