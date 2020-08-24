S = input()
cnt = 0
ans = 0
for i in range(len(S)):
    if S[i] == "W":
        ans += i - cnt
        cnt += 1
print(ans)