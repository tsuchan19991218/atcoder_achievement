from math import gcd

def lcm(a, b):
    _a = a
    while a % b != 0:
        a += _a
    return a


#def gcd(a, b):
 #   if a % b == 0:
  #      return a
   # return gcd(b, a % b)


N, M = map(int, input().split())
#N = max(_N, _M)
#M = min(_N, _M)
S = input()
T = input()
L = N * M // gcd(N, M)
#print(L)
s_now = 0
t_now = 0
while True:
    if S[s_now] != T[t_now]:
        print(-1)
        break
    s_now += L//M
    t_now += L//N
    if s_now >= N or t_now >= M:
        print(L)
        break
#print(L//M, L//N)
#print(N//gcd(N, M), M//gcd(N, M))


