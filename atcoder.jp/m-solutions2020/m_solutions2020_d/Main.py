N = int(input())
A = list(map(int, input().split()))
_A = [0] * (N - 1)
for i in range(len(A) - 1):
    if A[i] < A[i + 1]:
        _A[i] = 1
    elif A[i] > A[i + 1]:
        _A[i] = -1

money = 1000
cnt = 0
flag = 0
for i in range(len(_A)):
    if flag == 0 or flag == -1: #下落中
        if _A[i] == 1: #上がりそう
            cnt += money // A[i]
            money -= (money // A[i]) * A[i] #全部買う
            flag = 1
    elif flag == 0 or flag == 1: #上昇中
        if _A[i] == -1:
            money += cnt * A[i]  # 全部売る
            cnt = 0
            flag = -1
    #print(money)

money += cnt * A[N - 1]  # 全部売る
print(money)
