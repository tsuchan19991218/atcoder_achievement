H1, M1, H2, M2, K = map(int,input().split())

wake = H1 * 60 + M1
sleep = H2 * 60 + M2 - K
ans = 0
if wake <= sleep:
    ans = sleep - wake
else:
    time = 24 * 60
    ans = time - wake + sleep

print(ans)