from collections import Counter
s = input()
memo = [100] * 26
d = Counter(s)
for key in d.keys():
    index = [i for i, x in enumerate(s) if x == key]
    asc = ord(key) - 97
    memo[asc] = max(index[0], len(s) - 1 - index[-1])
    if len(index) >= 2:
        for i in range(1, len(index)):
            memo[asc] = max(memo[asc], index[i] - index[i-1] - 1)
print(min(memo))
