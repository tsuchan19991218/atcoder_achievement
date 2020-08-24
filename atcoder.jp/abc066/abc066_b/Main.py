S = input()
s = len(S)
i = 1
while True:
    _S = S[:-i]
    ls = len(_S)
    if _S[:ls//2] == _S[ls//2:]:
        break
    i += 1

print(s - i)