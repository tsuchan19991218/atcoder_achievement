A, B, C = map(int, input().split())
K = int(input())
while not B > A:
        B *= 2
        K -= 1
while not C > B:
        C *= 2
        K -= 1

if K < 0:
    print("No")
else:
    print("Yes")