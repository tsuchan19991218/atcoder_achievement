N = int(input())
h = list(map(int, input().split()))
#print([i for i, x in enumerate(l_dup) if x == 'x'])
ans = 0
#for i in range(-1):
    #print("unko")
while True:
    i_of_minus = [i for i, x in enumerate(h) if x <= 0]
    c = len(i_of_minus)
    #print(h)
    if c >= N:
        break
    if c == 0:
        ans += 1
        h = list(map(lambda x: x-1, h))
    else:
        if i_of_minus[0] != 0:
            ans += 1
        if i_of_minus[-1] != N - 1:
            ans += 1
        for j in range(1, c):
            if i_of_minus[j] - i_of_minus[j-1] > 1:
                ans += 1
        h = list(map(lambda x: x - 1, h))
print(ans)