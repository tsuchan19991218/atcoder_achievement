N = int(input())
s = []
for _ in range(N):
    s.append(int(input()))
s = sorted(s)
ans = sum(s)
i = 0
#print(s)
while ans % 10 == 0:
    ans = sum(s)
    #print(i)
    ans -= s[i]
    i += 1
    if i >= N:
        ans = 0
        break
print(ans)