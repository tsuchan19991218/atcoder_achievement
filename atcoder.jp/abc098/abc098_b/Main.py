N = int(input())
S = input()
ans = 0
for i in range(1, N):
    s_ = set(S[i:])
    _s = set(S[:i])
    s__s = s_ & _s
    ans = max(ans, len(s__s))
print(ans)