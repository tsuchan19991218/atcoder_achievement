s = list(input())
K = int(input())
s = list(map(lambda x: ord(x), s))
sub_s = []
for length in range(1, 6):
    for i in range(len(s) - (length - 1)):
        sub_s.append(s[i:i+length])
sub_s.sort()
k = 1
ans = sub_s[0]
for sub in sub_s:
    if ans == sub:
        if k == K:
            break
        continue
    ans = sub
    k += 1
    if k == K:
        break
for c in ans:
    print(chr(c), end="")
