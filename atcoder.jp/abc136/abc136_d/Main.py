S = input()
ans = [0] * len(S)
cnt = 0
for i in range(len(S) - 1):
    if S[i] + S[i + 1] == "RL":
        ans[i] += cnt // 2 + 1
        ans[i + 1] += cnt - (cnt // 2) + 1
        cnt = 0
    elif S[i] == "R":
        cnt += 1
#print(ans)
for i in range(1, len(S)):
    if S[-i] + S[-(i + 1)] == "LR":
        ans[-i] += cnt // 2
        ans[-(i + 1)] += cnt - (cnt // 2)
        cnt = 0
    elif S[-i] == "L":
        cnt += 1
for _ans in ans:
    print(_ans, end = " ")