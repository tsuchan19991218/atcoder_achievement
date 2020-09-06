from collections import Counter
w = input()
cnt = Counter(w)
for key in cnt.keys():
    if cnt[key] % 2 == 1:
        print("No")
        break
else:
    print("Yes")
