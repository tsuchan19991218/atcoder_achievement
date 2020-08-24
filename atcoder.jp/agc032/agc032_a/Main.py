N = int(input())
b = [0] + list(map(int, input().split()))
#print(b[N])
flag = [1] * (N + 1) #抜き取った番号を記録する配列
ans = []
i = N
_i = 0
while True:
    #print(i - _i)
    if b[i - _i] > i - _i:
        print(-1)
        exit()
        break
    elif b[i - _i] == i - _i:
        ans.append(i - _i)
        del b[i - _i]
        i -= 1
        _i = 0
    else:
        _i += 1
    if _i >= i:
        #print(list(reversed(ans)))
        break
for a in reversed(ans):
    print(a)