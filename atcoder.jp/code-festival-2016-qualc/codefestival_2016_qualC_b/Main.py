import math
k, t = map(int, input().split())
a = list(map(int, input().split()))
max_a = max(a)
rest_a = sum(a) - max_a
print(max(max_a - 1 - rest_a, 0))