a, b, c, d = map(int, input().split())
cnt1 = 0
cnt2 = a + b + c + d
for i in range(2):
    for j in range(2):
        for k in range(2):
            for l in range(2):
                cnt1 = 0
                cnt2 = a + b + c + d
                if i == 0:
                    cnt1 += a
                if j == 0:
                    cnt1 += b
                if k == 0:
                    cnt1 += c
                if l == 0:
                    cnt1 += d
                cnt2 -= cnt1
                if cnt1 == cnt2:
                    print("Yes")
                    exit()
print("No")