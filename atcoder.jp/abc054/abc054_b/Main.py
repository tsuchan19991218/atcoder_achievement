N, M = map(int, input().split())
A = []
B = []
for _ in range(N):
    A.append(input())
for _ in range(M):
    B.append(input())
flag = 0
for n_i in range(N - M + 1):
    for n_j in range(N - M + 1):
        for m_i in range(M):
            for m_j in range(M):
                if A[n_i + m_i][n_j + m_j] == B[m_i][m_j]:
                    continue
                break
            else:
                continue
            break
        else:
            flag = 1
            break
    else:
        continue
    break
if flag == 1:
    print("Yes")
else:
    print("No")