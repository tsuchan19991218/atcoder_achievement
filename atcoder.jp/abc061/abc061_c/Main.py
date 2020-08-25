n, k = map(int, input().split())
a_b = []
for _ in range(n):
    _a, _b = map(int, input().split())
    a_b.append((_a, _b))
a_b = sorted(a_b, key=lambda x: x[0])
i = 0
while k > a_b[i][1]:
    k -= a_b[i][1]
    i += 1
print(a_b[i][0])