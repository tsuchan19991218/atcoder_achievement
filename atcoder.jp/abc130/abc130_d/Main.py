from itertools import accumulate
N, K = map(int, input().split())
a = list(map(int, input().split()))
sum_a = list(accumulate(a))
ans = 0
end_index = []
b = 0
e = 1
while b < N:
    #print(sum_a[e-1], sum_a[b-1])
    if b == 0:
        if sum_a[e - 1] >= K:
            ans += 1
            end_index.append(e)
            b += 1
            continue
    else:
        if sum_a[e-1] - sum_a[b-1] >= K:
            ans += 1
            end_index.append(e)
            b += 1
            continue
    e += 1
    if e > N:
        break
#print(sum_a)
#print(end_index)
print((N+1) * len(end_index) - sum(end_index))