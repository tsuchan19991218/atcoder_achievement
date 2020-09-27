import random
from collections import Counter
id, N, K = [int(i) for i in input().split()]
S = []
for i in range(N):
    S.append(list(input()))

Q = 200
x = 50
y = 50
k = int(S[49][49])
print(Q)
for i in range(40):
    print(x, y, k)
    k += 1
    if k == 10:
        k = 1
x = 25
y = 25
k = int(S[24][24])
for i in range(40):
    print(x, y, k)
    k += 1
    if k == 10:
        k = 1
x = 75
y = 75
k = int(S[74][74])
for i in range(40):
    print(x, y, k)
    k += 1
    if k == 10:
        k = 1
x = 25
y = 75
k = int(S[26][74])
for i in range(40):
    print(x, y, k)
    k += 1
    if k == 10:
        k = 1
x = 75
y = 25
k = int(S[74][26])
for i in range(40):
    print(x, y, k)
    k += 1
    if k == 10:
        k = 1

