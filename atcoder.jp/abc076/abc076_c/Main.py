S = input()
T = input()
t_len = len(T)
s_len = len(S)
index = 0
if t_len > s_len:
    print("UNRESTORABLE")
    exit()
for i in range((s_len - 1) - (t_len - 1), -1, -1):
    for j in range(t_len):
        if S[i + j] == "?":
            continue
        if S[i + j] != T[j]:
            break
    else:
        index = i
        break
    continue
else:
    print("UNRESTORABLE")
    exit()
S = list(S)
for i in range(s_len):
    if S[i] == "?":
        S[i] = 'a'
S[index:index + t_len] = T
print("".join(S))
#print(S)

