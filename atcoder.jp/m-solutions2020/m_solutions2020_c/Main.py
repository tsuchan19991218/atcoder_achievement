N, K = map(int, input().split())
A = list(map(int, input().split()))
ans = [-1] * N

for i in range(K, N):
    #print(i-K, i, sep= " ")
    if A[i - K] < A[i]:
        print("Yes")
    else:
        print("No")
