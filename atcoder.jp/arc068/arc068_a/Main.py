x = int(input())
_x = x % 11
if _x <= 6:
    if _x == 0:
        _x = 0
    else:
        _x = 1
else:
    _x = 2

print((x // 11) * 2 + _x)
