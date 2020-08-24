N = int(input())
A = list(map(int, input().split()))

ans = 1

if 0 in A:
    print(0)
else:
    for a in A:
        ans *= a
        if ans > 1000000000000000000:
            print(-1)
            break
    else:
        print(ans)
        