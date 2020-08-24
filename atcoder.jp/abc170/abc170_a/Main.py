x = list(map(int, input().split()))
ans = 0
for i in range(len(x)):
    if x[i] == 0:
        ans = i+1
        break

print(ans)