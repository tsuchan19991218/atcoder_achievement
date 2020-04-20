N = int(input())
d = []
for _ in range(N):
    d.append(int(input()))

d.sort()

count = 1
for i in range(1, N):
    if d[i] != d[i-1]:
        count += 1
print(count)