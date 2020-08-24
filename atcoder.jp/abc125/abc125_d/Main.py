N = int(input())
A = list(map(int, input().split()))
abs_A = list(map(lambda x: abs(x), A))
abs_A = sorted(abs_A)
min_cnt = 0
ans = 0
#print(A)
for a in A:
    if a < 0:
        min_cnt += 1
    ans += abs(a)
#print(min_cnt)
if min_cnt % 2 == 1:
    ans -= 2 * abs_A[0]
print(ans)