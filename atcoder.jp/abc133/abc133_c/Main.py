l, r = map(int, input().split())
dif = r - l
ans = 30000
if dif >= 2019:
    ans = 0
else:
    mod_l = l % 2019
    mod_r = r % 2019
    if mod_l < mod_r:
        if 3 >= mod_l and mod_r >= 673:
            ans = 0
        else:
            for i in range(mod_l, mod_r + 1):
                for j in range(i + 1, mod_r + 1):
                    ans = min(ans, (i * j) % 2019)
    else:
        ans = 0
#print(dif, mod_l, mod_r)
print(ans%2019)