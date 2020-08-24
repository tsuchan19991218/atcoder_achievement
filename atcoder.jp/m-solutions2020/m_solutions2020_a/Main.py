X = int(input())
a = 400
ans = 8
while True:
    if X >= a and X <= a + 199:
        print(ans)
        break
    else:
        a += 200
        ans -= 1
