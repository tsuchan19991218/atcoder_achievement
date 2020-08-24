N = int(input())
job = []
for i in range(N):
    a, b = map(int, input().split())
    job.append([a, b])
#print(job)
job.sort(key=lambda x: x[1])
#print(job)
for i in range(1, N):
    job[i][0] += job[i - 1][0]
for i in range(N):
    if job[i][0] > job[i][1]:
        print("No")
        break
else:
    print("Yes")