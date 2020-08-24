from collections import Counter
S = input()
l = Counter(S)
a = l["a"]
b = l["b"]
c = l["c"]
if max(a, b, c) - min(a, b, c) > 1:
    print("NO")
else:
    print("YES")