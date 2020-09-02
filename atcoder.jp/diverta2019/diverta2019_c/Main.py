n = int(input())
ans = 0
s = []
ryotan = 0
atama = 0
oshiri = 0
for _ in range(n):
    _s = input()
    if _s[0] == "B" and _s[-1] == "A":
        ryotan += 1
    elif _s[0] == "B":
        atama += 1
    elif _s[-1] == "A":
        oshiri += 1
    A_flag = 0
    for c in _s:
        if c == "A" and A_flag == 0:
            A_flag = 1
        elif A_flag:
            if c == "B":
                ans += 1
                A_flag = 0
            elif c == "A":
                continue
            else:
                A_flag = 0
# print(ans)
# print(ryotan, atama, oshiri)
if ryotan > 1:
    ans += ryotan - 1
if ryotan > 0:
    if atama > 0:
        ans += 1
        atama -= 1
    if oshiri > 0:
        ans += 1
        oshiri -= 1
ans += min(atama, oshiri)
print(ans)