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
    return a

N = int(input())
n_root = prime_factorize(N)
n_set = list(set(n_root))

ans = 0
for num in n_set:
    item = n_root.count(num)
    i = 1
    while item >= i:
        item -= i
        ans += 1
        i += 1

print(ans)