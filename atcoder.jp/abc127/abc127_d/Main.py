N, M = map(int, input().split())
A = sorted(list(map(int, input().split())))
ans = 0
BC = []
for i in range(M):
    b, c = map(int, input().split())
    BC.append((b, c))
BC = sorted(BC, key=lambda x: x[1], reverse=True)
list = []
for bc in BC:
    for _ in range(bc[0]):
        list.append(bc[1])
        if len(list) == N:
            break
    else:
        continue
    break
#print(list)
#for i in range(1, N):
#    A[i] += A[i-1]
#for i in range(1, len(list)):
#    list[i] += list[i-1]
for i in range(min(N, len(list))):
    if A[i] >= list[i]:
        break
    A[i] = list[i]
print(sum(A))

