N = int(input())
S = input()

pls = S.count("R") * S.count("G") * S.count("B")
minus_count = 0
for i in range(len(S)):
    for j in range(i + 1, len(S)):
        if S[i] == S[j]:
            continue
        dis = j - i
        k = j + dis
        if k > len(S) - 1:
            break
        if S[i] == S[k]:
            continue
        elif S[j] == S[k]:
            continue
        minus_count += 1
print(pls - minus_count)