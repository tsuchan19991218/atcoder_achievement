N, M = map(int, input().split())
student = [[0] for _ in range(N+1)]
point = [[0] for _ in range(M+1)]
for i in range(1, N+1):
    student[i] = list(map(int, input().split()))
for i in range(1, M+1):
    point[i] = list(map(int, input().split()))

for i in range(1, N+1):
    this_ans = 0
    pre_min_dict = 2000000001 * 2
    for j in range(1, M+1):
        this_dict = abs(student[i][0] - point[j][0]) + abs(student[i][1] - point[j][1])
        if pre_min_dict > this_dict:
            this_ans = j
            pre_min_dict = this_dict
    print(this_ans)
