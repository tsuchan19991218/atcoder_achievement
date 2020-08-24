N = int(input())
a = list(map(int, input().split()))
a = list(map(lambda x: min(x // 400, 8), a))
#print(a)
m = len(set(a))
M = len(set(a))
if 8 in a:
    m -= 1
    M += a.count(8)
    M -= 1
#M = min(M, 8)
if m == 0:
    m = 1
print(m, M)