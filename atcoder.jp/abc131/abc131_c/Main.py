import math
a, b, c, d = map(int, input().split())
e = c * d //math.gcd(c, d)
ans = b - a + 1
cnt_of_c = (b // c) - ((a - 1) // c)
cnt_of_d = (b // d) - ((a - 1) // d)
cnt_of_e = (b // e) - ((a - 1) // e)
ans -= cnt_of_c + cnt_of_d - cnt_of_e
#print(cnt_of_c, cnt_of_d, cnt_of_e)
print(ans)