n = int(input())
b = [-1] * 2
my_buka = [[] for i in range(n + 1)]
my_saraly = [0] * (n + 1)
for id in range(2, n + 1):
    boss = int(input())
    my_buka[boss].append(id)
# print(my_buka)
for id in reversed(range(1, n + 1)):
    if len(my_buka[id]) == 0:
        my_saraly[id] = 1
        continue
    buka_max_s = 0
    buka_min_s = 10000000000
    for buka_id in my_buka[id]:
        buka_max_s = max(buka_max_s, my_saraly[buka_id])
        buka_min_s = min(buka_min_s, my_saraly[buka_id])
    my_saraly[id] = buka_min_s + buka_max_s + 1
print(my_saraly[1])