X, K, D = map(int, input().split())
first = 0
if X < 0:
    first = -1
elif X > 0:
    first = 1
ans = 0
X = abs(X)
judge = 0 # 奇数なら1偶数なら0
if first == 0:
    if D % 2 == 1:
        ans = D
    else:
        ans = 0
else:
    if K < X // D:
        ans = X - (K * D)
    else:
        judge = (X // D) % 2
        if judge == 0:
            if K % 2 == 0:
                ans = X % D
            else:
                ans = X % D - D
        else:
            if K % 2 == 0:
                ans = X % D - D
            else:
                ans = X % D
print(abs(ans))
