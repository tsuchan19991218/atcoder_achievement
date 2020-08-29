t = int(input())
n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))
sell_cnt = 0
i = 0
while i < n and sell_cnt < m:
    if a[i] > b[sell_cnt]:
        print("no")
        exit()
    if a[i] + t < b[sell_cnt]:
        i += 1
        continue
    i += 1
    sell_cnt += 1
if sell_cnt == m:
    print("yes")
else:
    print("no")
# print(sell_cnt)