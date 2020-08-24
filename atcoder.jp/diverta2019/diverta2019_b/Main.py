R, G, B, N = map(int, input().split())
cnt = 0
for b in range(((N + 1) // B) + 1):
    for g in range(((N + 1) // G) + 1):
        if B * b + G * g > N:
            continue
        if (N - (B * b + G * g)) % R == 0:
            cnt += 1
print(cnt)
