from collections import Counter
n, k = map(int, input().split())
name = input()
kit = input()

name_c = Counter(name)
kit_c = Counter(kit)

ans = 0
for name_key in name_c.keys():
    if name_key not in kit_c.keys():
        print(-1)
        exit()
    ans = max(ans, (name_c[name_key] + kit_c[name_key] - 1) // kit_c[name_key])
print(ans)

