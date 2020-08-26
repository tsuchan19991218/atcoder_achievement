A, B, x = map(int, input().split())
b = 0
e = 1000000001
num = 0
d_n = 0
while abs(e - b) > 1:
    num = (e + b) // 2
    d_n = len(str(num))
    #print(b, e, num)
    if (A * num) + (B * d_n) <= x:
        b = num
    else:
        e = num
# ans = num + 1
# ans_d = len(str(ans))
print(b)
# if A * ans + B * ans_d <= x:
#     print(min(ans, 1000000000))
#     exit()
# if B * num + B * d_n <= x:
#     print(num)
#     exit()
# else:
#     print(num - 1)