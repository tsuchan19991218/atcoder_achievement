X, Y = map(int, input().split())
m = 2 * X
M = 4 * X

if Y % 2 == 1:
    print("No")
elif Y > M or Y < m:
    print("No")
else:
    print("Yes")