S, c = map(int, input().split())
if 2 * S > c:
    print(c // 2)
    exit()
ans = S
rest_c = c - 2 * S
ans += rest_c // 4
print(ans)