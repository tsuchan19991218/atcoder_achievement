N = int(input())
t = [0] * (N+1)
x = [0] * (N+1)
y = [0] * (N+1)
for i in range(1, N + 1):
    t[i], x[i], y[i] = map(int, input().split())

for i in range(1, N + 1):
    t_dif = t[i] - t[i - 1]
    dict = abs(x[i] - x[i-1]) + abs(y[i] - y[i-1])
    #print(t_dif, dict)
    if t_dif < dict or t_dif % 2 != dict % 2:
        print("No")
        break
else:
    print("Yes")

