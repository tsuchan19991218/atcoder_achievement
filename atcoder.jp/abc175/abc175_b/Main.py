N = int(input())
L = list(map(int, input().split()))
L = list(reversed(sorted(L)))
#print(L)
ans = 0
for i in range(len(L)):
    for j in range(i + 1, len(L)):
        for k in range(j + 1, len(L)):
            #print(L[i], L[j], L[k])
            if L[i] > L[j] and L[j] > L[k] and L[j] + L[k] > L[i]:
                ans += 1
print(ans)