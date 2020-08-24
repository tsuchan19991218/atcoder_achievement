N = int(input())
c = list(input())
ans = 0
cnt = c.count("W")
ans = c[N-cnt:].count("R")
if cnt != 0:
    print(ans)
else:
    print(0)