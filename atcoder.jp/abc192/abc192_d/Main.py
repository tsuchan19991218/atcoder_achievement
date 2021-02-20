x = input()
m = int(input())

def get_num(x, n):
    #print(str(n) + "真数")
    x = reversed(x)
    d = 1
    ans = 0
    for c in x:
        #print(d, int(c), sep=' ')
        ans += d * int(c)
        d *= n
    #print(ans)
    return ans


if len(x) == 1:
    if int(x[0]) <= m:
        print(1)
    else:
        print(0)
    exit()

max_chr = 0
for c in x:
    max_chr = max(max_chr, int(c))

keta = len(x)
tmp = (18 + (keta - 1) - 1) // (keta - 1)
sinsu_max = 10 ** tmp
sinsu_max += 5

r = sinsu_max
l = 1
#print(sinsu_max)
while (r - l) > 1:
    mid = (r + l) // 2
    if get_num(x, mid) <= m:
        l = mid
    else:
        r = mid
print(max(0, l - max_chr))