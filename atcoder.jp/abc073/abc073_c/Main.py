from collections import Counter
N = int(input())
A = []
for _ in range(N):
    A.append(int(input()))
#sA = set(A)
ans = 0
for num in Counter(A).values():
    #print(num)
    if num % 2 == 1:
        ans += 1
print(ans)