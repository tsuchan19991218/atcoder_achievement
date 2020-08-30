from collections import Counter
s = input()
i = 0
while i < len(s):
    if s[i] == 'd':
        S = s[i:i + 5]
        if i + 6 < len(s):
            if S + s[i + 5] + s[i + 6] == "dreamer":
                i += 7
                if i + 3 < len(s):
                    if s[i:i + 4] == "aser":
                        i += 4
                        continue
                if i + 2 < len(s):
                    if s[i:i + 3] == "ase":
                        i += 3
                        continue
                continue
        if S == "dream":
            i += 5
            continue
        break
    elif s[i] == 'e':
        S = s[i:i + 5]
        if i + 5 < len(s):
            if S + s[i + 5] == "eraser":
                i += 6
                continue
        if S == "erase":
            i += 5
            continue
        break
    else:
        break
    if i + 4 >= len(s):
        break
else:
    print("YES")
    exit()
print("NO")