N, M = map(int, input().split())
sc = [[] for _ in range(M)]
for i in range(M):
    sc[i] = list(map(int, input().split()))


S = " " * N
sc = list(set(map(tuple, sc)))

memo = [-1] * N
S = list(S)
for numbers in sc:
    if memo[numbers[0]-1] == -1 or S[numbers[0]-1] == numbers[1]:
        S[numbers[0]-1] = str(numbers[1])
        memo[numbers[0]-1] = 1
    else:
        print(-1)
        break

    if numbers == (1, 0) and N > 1:
        print(-1)
        break
else:
    for i in range(N):
        if S[i] == " ":
            if i == 0 and N > 1:
                S[i] = "1"
            else:
                S[i] = "0"
    S = list(map(int, S))
    for i in range(len(S)):
        print(S[i], end="")




        