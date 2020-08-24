S = input()
num = [0] * (len(S) + 1)
min_cnt = 0
plu_cnt = 0
flag = 0
ans = 0
if S[0] == ">":
    flag = 1
for i in range(len(S)):
    if flag == 1:
        if S[i] == "<":
            flag = 0
            plu_cnt = 0
        else:
            plu_cnt += 1
            ans += plu_cnt
    if S[i] == "<":
        if min_cnt == 0:
            plu_cnt += 1
        else: #ansに精算する
            M = max(plu_cnt, min_cnt)
            m = min(plu_cnt, min_cnt)
           # ans += ((plu_cnt+1)*plu_cnt)/2
           # ans += (min_cnt*(min_cnt-1))/2
            ans += ((M + 1) * M) // 2
            ans += (m*(m-1))//2
            plu_cnt, min_cnt = 0, 0
            plu_cnt += 1
    elif S[i] == ">" and flag == 0:
        min_cnt += 1
if flag == 1:
    plu_cnt, min_cnt = 0, 0
M = max(plu_cnt, min_cnt)
m = min(plu_cnt, min_cnt)
ans += ((M + 1) * M)//2
ans += (m*(m-1))//2
print(ans)