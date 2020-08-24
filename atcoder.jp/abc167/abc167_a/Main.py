S = input()
T = input()

s = len(S)
t = len(T)

if s+1 == t:
    for i in range(s):
        if S[i] != T[i]:
            print("No")
            break
    else:
        print("Yes")
else:
    print("No")