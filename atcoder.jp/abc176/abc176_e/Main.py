from collections import Counter
H, W, M = map(int, input().split())
h = [0] * M
w = [0] * M
h_w = {}
for i in range(M):
    h[i], w[i] = map(int, input().split())
    h_w[(h[i], w[i])] = 1
hl = Counter(h)
hl = list(reversed(sorted(hl.items(), key=lambda x:x[1])))
wl = Counter(w)
wl = list(reversed(sorted(wl.items(), key=lambda x:x[1])))
ans = 0
#print(hl)
#print(wl)
max_hl = hl[0][1]
max_wl = wl[0][1]
ans = max_hl + max_wl
end_flag = 0
max_flag = 1
for i in range(len(hl)):
    for j in range(len(wl)):
        if hl[i][1] < max_hl:
            end_flag = 1
            break
        if wl[j][1] < max_wl:
            break
        if (hl[i][0], wl[j][0]) in h_w.keys():
            continue
        else:
            end_flag = 1
            max_flag = 0
            break
    else:
        continue
    if end_flag == 1:
        break
print(ans - max_flag)
