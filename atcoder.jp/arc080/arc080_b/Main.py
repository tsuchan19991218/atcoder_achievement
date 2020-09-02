h, w = map(int, input().split())
n = int(input())
a = list(map(int, input().split()))
ans = [[0] * w for _ in range(h)]
now_color = 1
now_a_index = now_color - 1
ans_index = [0, 0]
for i in range(h * w):
    ans[ans_index[0]][ans_index[1]] = now_color
    a[now_a_index] -= 1
    if a[now_a_index] == 0:
        now_color += 1
        now_a_index += 1
    ans_index[1] += 1
    if ans_index[1] >= w:
        ans_index[1] = 0
        ans_index[0] += 1
cnt = 0
for l_ans in ans:
    if cnt % 2 == 1:
        for ll_ans in reversed(l_ans):
            print(ll_ans, end=" ")
        cnt += 1
    else:
        for ll_ans in l_ans:
            print(ll_ans, end=" ")
        cnt += 1
    print("")