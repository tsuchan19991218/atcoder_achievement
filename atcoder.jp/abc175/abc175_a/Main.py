S = input()
box = 0
ans = 0
for s in S:
    if s == "R":
        box += 1
    else:
        box = 0
    ans = max(ans, box)
print(ans)