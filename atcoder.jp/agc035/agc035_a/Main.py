from collections import Counter
N = int(input())
a = list(map(int, input().split()))
l = Counter(a)
all_xor = 0
if N % 3 != 0:
    if l[0] != N:
        print("No")
        exit()
    else:
        print("Yes")
        exit()
for _l in l.keys():
    if l[_l] == N // 3:
        continue
    if _l == 0:
        if l[0] == N:
            print("Yes")
            exit()
        if l[0] != N // 3 or len(l) != 2:
            print("No")
            exit()
    if l[_l] == (2 * N) // 3 and l[0] == N // 3:
        print("Yes")
        exit()
    else:
        print("No")
        exit()
for i in range(N):
    all_xor = a[i] ^ all_xor
if all_xor == 0:
    print("Yes")
else:
    print("No")
