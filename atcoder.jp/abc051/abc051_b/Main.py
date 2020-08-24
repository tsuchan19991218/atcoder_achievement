K, S = map(int, input().split())
ans = 0
for x in range(K + 1):
    for y in range(K + 1):
        rest = S - (x + y)
        if rest >= 0 and rest <= K:
            ans += 1
print(ans)