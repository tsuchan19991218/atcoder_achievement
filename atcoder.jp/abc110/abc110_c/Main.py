s = list(input())
t = list(input())

s = list(map(ord, s))
t = list(map(ord, t))
s_to_t = [-1] * 200
t_to_s = [-1] * 200

for i in range(len(s)):
    if s_to_t[s[i]] == -1:
        s_to_t[s[i]] = t[i]
    else:
        if s_to_t[s[i]] != t[i]:
            print("No")
            break
    if t_to_s[t[i]] == -1:
        t_to_s[t[i]] = s[i]
    else:
        if t_to_s[t[i]] != s[i]:
            print("No")
            break
else:
    print("Yes")


