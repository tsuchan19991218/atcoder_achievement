A = []
memo = [-1] * 101
for i in range(3):
    a, b, c = map(int, input().split())
    memo[a] = memo[b] = memo[c] = i
    A.append([a, b, c])
n = int(input())
b = []
for _ in range(n):
    b.append(int(input()))
b = set(b)
ana = [[0] * 3 for _ in range(3)]
for num in b:
    if memo[num] == -1:
        continue
    ana[memo[num]][A[memo[num]].index(num)] = 1
#斜め
if ana[0][0] == 1 and ana[1][1] == 1 and ana[2][2] == 1:
    print("Yes")
    exit()
if ana[0][2] == 1 and ana[1][1] == 1 and ana[2][0] == 1:
    print("Yes")
    exit()
#横 縦
for i in range(3):
    if ana[i][0] == 1 and ana[i][1] == 1 and ana[i][2] == 1:
        print("Yes")
        exit()
    if ana[0][i] == 1 and ana[1][i] == 1 and ana[2][i] == 1:
        print("Yes")
        exit()
print("No")


