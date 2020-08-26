from collections import Counter
n, p = map(int, input().split())


def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr


list = factorization(p)
#print(list)
ans = 1
for l in list:
    c = l[1] // n
    ans *= l[0] ** c
print(ans)