n = int(input())
a = reversed(list(map(int, input().split())))
ans = [-1] * n
i = 0
for _a in a:
    if i % 2 == 0:
        ans[i // 2] = _a
    else:
        ans[-((i // 2) + 1)] = _a
    i += 1
for _ans in ans:
    print(_ans, end=" ")
