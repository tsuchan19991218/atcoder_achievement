N, M = map(int, input().split())
H = list(map(int, input().split()))
AB = [[] for i in range(M)]
for i in range(M):
    AB[i] = list(map(int, input().split()))

cnt = 0
memo_loser = []
for bridge in AB:
    

    value = min(H[bridge[0]-1], H[bridge[1]-1])
    if value == H[bridge[0]-1] and not bridge[0] in memo_loser:
        memo_loser.append(bridge[0])
    if value == H[bridge[1] - 1] and not bridge[1] in memo_loser:
        memo_loser.append(bridge[1])
print(N - len(memo_loser))
