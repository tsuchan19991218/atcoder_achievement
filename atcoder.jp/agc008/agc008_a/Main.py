x, y = map(int, input().split())
ans = 0
if abs(x) > abs(y):
    if y > 0:
        if x > 0:
            ans += 2
        elif x < 0:
            ans += 1
        ans += abs(x) - y
        print(ans)
        exit()
    else:
        if x > 0:
            ans += 1
        ans += abs(x) - abs(y)
        print(ans)
        exit()
else:
    if y > 0:
        if x < 0:
            ans += 1
        ans += y - abs(x)
        print(ans)
        exit()
    else:
        if x >= 0:
            ans += 1
        elif x < 0:
            ans += 2
        ans += abs(y) - abs(x)
        print(ans)
        exit()