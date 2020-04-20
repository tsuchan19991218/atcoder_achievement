N, Y = map(int, input().split())
x, y, z = -1, -1, -1

for i in range(N + 1):
    for j in range(N + 1):
        if i + j <= N:
            k = N - (i + j)
            money = 10000*i + 5000*j + 1000*k
            if money == Y:
                x = i
                y = j
                z = k
                break

print(x,y,z,sep=" ")