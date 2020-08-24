n, k = map(int, input().split())
s = [0] * n
for i in range(n):
    s[i] = int(input())
#print(s)
ans = 0
e = 1
num = s[0]
if 0 in s:
    ans = n
else:
    for b in range(n):
        if b + 1 > e:
            e = b + 1
            num *= s[e - 1]
        while e < n: #bに対しての最大のeを求める
            if num * s[e - 1 + 1] <= k:
                e += 1
                num *= s[e - 1]
            else:
                break
        if e - b == 1 and s[b] > k:
            ans = max(ans, 0)
        else:
            ans = max(ans, e - b)
        #print(num, b, e)
        num //= s[b]
print(ans)