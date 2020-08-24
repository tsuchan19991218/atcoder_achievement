a, b, x = map(int, input().split())
b_ans = b // x
a_ans = (a - 1) // x
print(b_ans - a_ans)