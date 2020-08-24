N, A, B = map(int, input().split())
dif = B - A
if dif == 0 and N == 1:
    print(1)
    exit()
if dif < 0 or N == 1:
    print(0)
    exit()
ans = (((B * N - dif) - (A * N + dif))  + 1)
print(ans)