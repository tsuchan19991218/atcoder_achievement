X, N = map(int, input().split())
P = list(map(int, input().split()))
nP = list(map(lambda x: abs(x - X), P))
nP.sort()

if N == 0:
    print(X)
elif nP[0] != 0:
    print(X)
else:
    cnt = 1
    while True:
        if nP.count(cnt) != 2:
            if not X - cnt in P:
                print(X - cnt)
            else:
                print(X + cnt)
            break
        cnt += 1
