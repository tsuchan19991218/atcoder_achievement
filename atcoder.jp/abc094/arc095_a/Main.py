n = int(input())
x = list(map(int, input().split()))
s_x = sorted(x)
small_ans = s_x[n//2 - 1]
large_ans = s_x[n//2]
for i in range(n):
    if x[i] < large_ans:
        print(large_ans)
    elif x[i] > small_ans:
        print(small_ans)
    else:
        print(small_ans)