K = int(input())
S = input()

s = len(S)

if s <= K:
    print(S)
else:
    print(S[:K] + "...")