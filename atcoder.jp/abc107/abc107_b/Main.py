H, W = map(int, input().split())
a = []
for i in range(H):
    y = input()
    if "#" in y:
        a.append(y)
#print(a)
#print(len(a))
ans = [""] * len(a)
for i in range(len(a[0])):
    flag = 0
    for j in range(len(a)):
        if a[j][i] == "#":
            flag = 1
    if flag == 1:
        for j in range(len(a)):
            ans[j] += a[j][i]
for i in range(len(ans)):
    print(ans[i])