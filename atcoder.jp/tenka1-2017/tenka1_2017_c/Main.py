n = int(input())
ans_a = 0
ans_b = 0
ans_c = 0
for b in range(1, 3501):
    for c in range(1, 3501):
        sita = 4 * b * c - (n * (b + c))
        if sita <= 0:
            continue
        ue = n * b * c
        if ue % sita == 0:
            ans_a, ans_b, ans_c = ue // sita, b, c
            break
print(ans_a, ans_b, ans_c)