def f(n, m, arrs=[], arr=[]):
    if len(arr) == n:
        arrs.append(arr)
    else:
        if len(arr) == 0:
            for i in range(1, m + 1):
                f(n, m, arrs, arr + [i])
        else:
            for i in range(arr[-1], m + 1):
                f(n, m, arrs, arr + [i])
    return arrs


n, m, q = map(int, input().split())
Q = []
for _ in range(q):
    a, b, c, d = map(int, input().split())
    Q.append((a, b, c, d))
#print(memo)
ans = 0
for ball in f(n, m):
    a = 0
    #print(ball)
    for q in Q:
        if ball[q[1] - 1] - ball[q[0] - 1] == q[2]:
            a += q[3]
    ans = max(ans, a)
print(ans)