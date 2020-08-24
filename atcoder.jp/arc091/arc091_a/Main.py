_N, _M = map(int, input().split())
N = max(_N, _M)
M = min(_N, _M)
if N >= 3 or M >= 3:
    long = max(1, N - 2)
    short = abs(M - 2)
    print(long * short)
else:
    if N == 1 and M == 1:
        print(1)
    else:
        print(0)