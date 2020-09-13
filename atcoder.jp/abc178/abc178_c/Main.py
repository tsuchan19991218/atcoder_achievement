n = int(input())
ans_max = 1
for i in range(n):
    ans_max = ans_max * 10 % 1000000007

ans_mid = 1
for i in range(n):
    ans_mid = ans_mid * 9 % 1000000007
ans_mid = ans_mid * 2 % 1000000007

ans_min = 1
for i in range(n):
    ans_min = ans_min * 8 % 1000000007
ans = (ans_max - (ans_mid - ans_min)) % 1000000007
print(ans)