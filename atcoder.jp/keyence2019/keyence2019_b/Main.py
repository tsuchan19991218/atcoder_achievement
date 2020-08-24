S = input()
c = "keyence"
if S[-7:] == c or S[:7] == c:
    print("YES")
else:
    for i in range(1, 7):
        c_, _c = c[:i], c[i:]
        if S[:i] == c_ and S[-(7-i):] == _c:
            print("YES")
            break
    else:
        print("NO")