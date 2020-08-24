import itertools
N = int(input())
S = list(input())
S = list(map(int, S))
first = [-1] * 10
#second = [-1] * 10
#third = [-1] * 10
ans = 0
for i in range(N):
    if first[S[i]] == 1:
        continue
    second = [-1] * 10
    for j in range(i + 1, N):
        if second[S[j]] == 1:
            continue
        third = [-1] * 10
        for k in range(j + 1, N):
            if third[S[k]] == 1:
                continue
            #print(S[i], S[j], S[k])
            ans += 1
            third[S[k]] = 1
        second[S[j]] = 1
    first[S[i]] = 1
print(ans)