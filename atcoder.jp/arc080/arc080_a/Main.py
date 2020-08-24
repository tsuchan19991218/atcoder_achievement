N = int(input())
A = list(map(int, input().split()))
cnt_4 = 0
cnt_2 = 0
for a in A:
    if a % 4 == 0:
        cnt_4 += 1
    elif a % 2 == 0:
        cnt_2 += 1
cnt = N - 2*cnt_4 - cnt_2
if cnt_4 > 0 and N % 2 == 1:
    cnt -= 1
if cnt <= 0:
    print("Yes")
else:
    print("No")