n = int(input())
a = list(map(int, input().split()))
ans = 10000000000
for num in range(-100, 101):
    kari_ans = 0
    for _a in a:
        kari_ans += (num - _a) ** 2
    ans = min(ans, kari_ans)
print(ans)
