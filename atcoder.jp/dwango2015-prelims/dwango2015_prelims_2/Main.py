s = int(input())
s = str(s)

i = 0
find_25_set = 0
ans = 0
while i < len(s) - 1:
    if s[i] + s[i + 1] == "25":
        find_25_set += 1
        i += 2
        continue
    if find_25_set > 0:
        ans += find_25_set * (find_25_set + 1) // 2
        find_25_set = 0
        i += 1
    else:
        i += 1
ans += find_25_set * (find_25_set + 1) // 2
print(ans)