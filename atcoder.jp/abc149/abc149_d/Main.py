n, k = map(int, input().split())
r, s, p = map(int, input().split())
t = input()
ans = [0] * k
for i in range(k):
    pre_cnt = ["", 0]
    for j in range(i, n, k):
        if j == i:
            if t[j] == "r":
                ans[i] += p
                pre_cnt = ["p", p]
            elif t[j] == "s":
                ans[i] += r
                pre_cnt = ["r", r]
            else:
                ans[i] += s
                pre_cnt = ["s", s]
            continue

        if t[j] == "r":
            if pre_cnt[0] == "p":
                pre_cnt[0] = ""
                continue
            ans[i] += p
            pre_cnt = ["p", p]
        elif t[j] == "s":
            if pre_cnt[0] == "r":
                pre_cnt[0] = ""
                continue
            ans[i] += r
            pre_cnt = ["r", r]
        else:
            if pre_cnt[0] == "s":
                pre_cnt[0] = ""
                continue
            ans[i] += s
            pre_cnt = ["s", s]
print(sum(ans))