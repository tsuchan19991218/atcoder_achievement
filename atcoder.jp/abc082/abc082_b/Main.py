s = input()
t = input()
s = list(map(lambda x: ord(x), s))
t = list(map(lambda x: ord(x), t))
s = sorted(s)
t = sorted(t, reverse=True)
num = min(len(s), len(t))
for i in range(num):
    if s[i] < t[i]:
        print("Yes")
        break
    elif t[i] < s[i]:
        print("No")
        break
else:
    if len(s) < len(t):
        print("Yes")
    else:
        print("No")