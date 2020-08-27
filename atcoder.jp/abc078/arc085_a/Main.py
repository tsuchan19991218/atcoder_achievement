n, m = map(int, input().split())
t_p = 2 ** m
time = (100 * (n - m) + 1900 * m)
ans = t_p * time
print(ans)
