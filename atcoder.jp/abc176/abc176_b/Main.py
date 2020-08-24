N = list(input())
N = list(map(int, N))
if sum(N) % 9 == 0:
    print("Yes")
else:
    print("No")
