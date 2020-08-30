from collections import Counter
n = int(input())
a = list(map(int, input().split()))
count_a = Counter(a)
new_a = [i for i in count_a.keys() if count_a[i] >= 2]
#print(new_a)
if len(new_a) < 2:
    print(0)
    exit()
new_a = sorted(new_a, reverse=True)
if count_a[new_a[0]] >= 4:
    ans = new_a[0] ** 2
else:
    ans = new_a[0] * new_a[1]
print(ans)