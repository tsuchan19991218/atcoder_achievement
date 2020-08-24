import math
X = int(input())
money = 100
ans_year = 0
while X > money:
    money *= 1.01
    money = math.floor(money)
    ans_year += 1
print(ans_year)