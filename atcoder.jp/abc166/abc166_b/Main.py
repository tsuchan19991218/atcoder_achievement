N, K = map(int, input().split())
d = []
A = [[] for i in range(K)]
for _ in range(K):
    D = int(input())
    d.append(D)
    A[_] = list(map(int, input().split()))

list = []

for a in A:
    for num in a:
        if num in list:
            continue
        list.append(num)

ans = N - len(list)

print(ans)