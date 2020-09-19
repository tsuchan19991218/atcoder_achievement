n = int(input())
d = [[0] for i in range(n)]
for i in range(n):
    d1, d2 = map(int, input().split())
    d[i].append(d1)
    d[i].append(d2)

seq = 0
ans = 0
for pair in d:
    if pair[1] == pair[2]:
        seq += 1
    else:
        seq = 0
    ans = max(ans, seq)
if ans >= 3:
    print("Yes")
else:
    print("No")
