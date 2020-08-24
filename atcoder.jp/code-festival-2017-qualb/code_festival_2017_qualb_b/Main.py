from collections import Counter
N = int(input())
D = list(map(int, input().split()))
M = int(input())
T = list(map(int, input().split()))

if len(D) < len(T):
    print("NO")
    exit()
D.sort()
T.sort()
dl = Counter(D)
tl = Counter(T)
for t in tl.keys():
    if not t in dl:
        print("NO")
        exit()
    if tl[t] > dl[t]:
        print("NO")
        exit()
print("YES")