#import numpy as np
N = int(input())
a = list(map(int, input().split()))
all_xor = 0
for _a in a:
    all_xor = all_xor ^ _a
for _a in a:
    print(all_xor ^ _a)



