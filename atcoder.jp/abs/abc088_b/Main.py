

N = int(input())
a = list(map(int, input().split()))
Alice = 0
Bob = 0

a.sort(reverse=True)
for i in range(len(a)):
    if i % 2 == 0:
        Alice += a[i]
    else:
        Bob += a[i]
print(Alice - Bob)
