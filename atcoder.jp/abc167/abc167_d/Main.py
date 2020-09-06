from collections import deque
n, k = map(int, input().split())
a = [-1] + list(map(int, input().split()))
town = [-1] * (n + 1)
town[1] = 0
now_town = 1
second_first = 0
while True:
    if town[a[now_town]] != -1:
        second_first = a[now_town]
        break
    town[a[now_town]] = town[now_town] + 1
    if town[a[now_town]] == k:
        print(a[now_town])
        exit()
    now_town = a[now_town]
    # print(town)
start_index = town[second_first]
end_index = max(town)
rest = k - end_index
div = (rest-1) % (end_index - start_index + 1)
# print(rest, div)
ans = town.index((start_index) + div)
print(ans)