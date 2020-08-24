import math
S = input()
ans = len(S)*(len(S)-1) * 2
#u_cnt = 0
#d_cnt = 0
for i in range(len(S)):
    if S[i] == "U":
        ans -= len(S) - 1 - i
    else:
        ans -= i
print(ans)