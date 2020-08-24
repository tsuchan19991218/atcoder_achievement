########関数部分##############
def Base_10_to_n(X, n):
    X -= 1
    if (int(X/n)):
            return Base_10_to_n((X)//n, n) + str(X%n) + " "
    return str(X%n) + " "
############################

def nanketa(X):
    n = 1
    a = 0
    while X > (26 ** n) + a:
        a += 26 ** n
        n += 1
    return n


#####関数をつかってみる．#####
######今回は二進数に変換######
x10 = int(input())
x2 = Base_10_to_n(x10, 26)
##print(x2)
ans = ""
a = ""
cnt = 0
x2 = list(x2.split(" "))[:-1]
x2 = list(map(int, x2))
#if x2[-1] == 25:
    #x2[-1] = -1
#x2[-1] += 1
##print(x2)
for x in x2:
    ans += chr(x + 97)

print(ans)