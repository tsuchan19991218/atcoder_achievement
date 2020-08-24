S = input()
ans = []
for i in range(len(S)):
    if S[i] == "0":
        ans.append("0")
    elif S[i] == "1":
        ans.append("1")
    else:
        if len(ans) > 0:
            del ans[-1]
ans_ = ""
for s in ans:
    ans_ += s
print(ans_)