import math


def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return set(a)


n = int(input())
a = list(map(int, input().split()))
num = a[0]
for i in range(1, n):
    num = math.gcd(num, a[i])
if num != 1:
    print("not coprime")
    exit()
prime_memo = {}
for i in range(n):
    prime_number = prime_factorize(a[i])
    for num in prime_number:
        if num not in prime_memo.keys():
            prime_memo[num] = 1
        else:
            print("setwise coprime")
            exit()
print("pairwise coprime")
