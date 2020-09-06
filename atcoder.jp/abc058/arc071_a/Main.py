from collections import  Counter
n = int(input())
s = []
for _ in range(n):
    _s = sorted(input())
    s.append(_s)

chr_cnt = Counter(s[0])
for i in range(1, n):
    kari_chr_cnt = Counter(s[i])
    for key in chr_cnt.keys():
        if key not in kari_chr_cnt.keys():
            chr_cnt[key] = 0
            continue
        chr_cnt[key] = min(chr_cnt[key], kari_chr_cnt[key])
ans = ""
for key in chr_cnt.keys():
    ans += key * chr_cnt[key]
print(''.join(sorted(ans)))

