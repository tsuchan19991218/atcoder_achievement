s = input()
t = input()
cnt = []
for i in range(len(s) - len(t) + 1):
    c = 0
    for j in range(len(t)):
        if s[i + j] == t[j]:
            c += 1
    cnt.append(c)
ans = len(t) - max(cnt)
print(ans)