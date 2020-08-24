S = input()
T = input()
ans = 0
for i in range(len(S)):
    if S[i] == T[i]:
        continue
    else:
        ans += 1
print(ans)