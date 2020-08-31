import heapq


def make_ans(str1, str2):
    while len(str1) < 6:
        str1 = '0' + str1
    while len(str2) < 6:
        str2 = '0' + str2
    return str1 + str2


n, m = map(int, input().split())
ken = [[] for _ in range(n + 1)]
# for i in range(1, n + 1):
#     heapq.heapify(ken[i])
memo = []
for i in range(1, m + 1):
    p, y = map(int, input().split())
    ken[p].append(y)
    memo.append((p, y))
for i in range(1, n + 1):
    ken[i].sort()
# print(ken)
for q in memo:
    ans_left = str(q[0])
    begin = 0
    end = len(ken[q[0]]) - 1
    ans_index = -1
    mid = 0
    while True:
        # if q[0] == 2:
        #     print(ken[q[0]])
        mid = (end + begin) // 2
        if ken[q[0]][mid] > q[1]:
            end = mid
        elif ken[q[0]][mid] < q[1]:
            begin = mid
        else:
            ans_index = mid
            break
        if ken[q[0]][end] == q[1]:
            ans_index = end
            break
        elif ken[q[0]][begin] == q[1]:
            ans_index = begin
            break
    ans_right = str(ans_index + 1)
    print(make_ans(ans_left, ans_right))