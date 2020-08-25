n = int(input())
b = 1
e = 100000
score = 0
while True:
    mid = (e + b) // 2
    score = (mid * (mid + 1)) // 2
    if score >= n:
        e = mid
    else:
        b = mid
    if abs(e - b) <= 1:
        break
    #print(mid)
if b * (b + 1) // 2 >= n:
    ans = b
else:
    ans = e

rest = ((ans * (ans + 1)) // 2) - n
for num in range(1, ans + 1):
    if rest == num:
        continue
    print(num)