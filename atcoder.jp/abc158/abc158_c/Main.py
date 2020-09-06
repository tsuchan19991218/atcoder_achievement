a, b = map(int, input().split())

for num in range(1, 2000):
    if int(num * 0.08) == a and int(num * 0.1) == b:
        print(num)
        exit()
else:
    print(-1)