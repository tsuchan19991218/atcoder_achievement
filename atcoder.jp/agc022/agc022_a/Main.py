S = input()
a = 97
for i in range(26):
    if not chr(a + i) in S:
        S += chr(a + i)
        ans = S
        break
else:
    memo = [-1] * 200 #使える文字を記録
    flag = 0
    while True:
        i = 0
        while ord(S[-1]) + i < a + 26:
            #print(chr(ord(S[-1]) + i))
            if memo[ord(S[-1]) + i] == 1: #使える文字が見つかった
                s = chr(ord(S[-1]) + i)
                S = S[:-1] + s
                ans = S
                flag = 1
                break
            i += 1
        if flag == 1:
            break
        memo[ord(S[-1])] = 1
        S = S[:-1]
        if len(S) <= 0:
            ans = -1
            break
print(ans)