N = int(input())
s = input()
t = input()
ans = N
i = 0
if s == t:
    print(ans)
    exit()
while ans < 2 * N:
    if s[i:] == t[:-i]:
        break
    i += 1
    ans += 1
print(ans)