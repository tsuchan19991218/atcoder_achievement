n = int(input())
l = list(map(int, input().split()))
l.sort(reverse=True)
ans = 0
c = n - 1
for a in range(n - 2):
    c = n - 1
    for b in range(a + 1, n - 1):
        #　各a,bに対してのcを尺取法で探索
        while l[a] >= l[b] + l[c]:
            c -= 1
            if c <= b:
                break
        else:
            # print(l[a], l[b], l[c])
            ans += c - b
            continue
        break
print(ans)