c = []
for _ in range(3):
    c.append(list(map(int, input().split())))

j1 = c[0][0] - c[0][1]
j2 = c[0][1] - c[0][2]
for i in range(1, 3):
    _j1 = c[i][0] - c[i][1]
    _j2 = c[i][1] - c[i][2]
    if j1 == _j1 and j2 == _j2:
        continue
    print("No")
    break
else:
    print("Yes")