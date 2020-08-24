A, B, C, K = map(int, input().split())
cnt = 0
if A < K:
    K -= A
    cnt += A
    if B < K:
        K -= B
        cnt -= K

else:
    cnt += K

print(cnt)
