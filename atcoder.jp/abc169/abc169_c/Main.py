import math
A, B = input().split()
A = int(A)
B = int(B[0] + B[2] + B[3])
ans = str(A * B)
if len(ans) > 3:
    print(ans[:-2])
else:
    print(0)
