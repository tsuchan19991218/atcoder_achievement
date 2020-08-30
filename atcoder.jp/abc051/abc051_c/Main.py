sx, sy, tx, ty = map(int, input().split())
yoko = tx - sx
tate = ty - sy
#まず一周
for _ in range(yoko):
    print("R", end="")
for _ in range(tate):
    print("U", end="")
for _ in range(yoko):
    print("L", end="")
for _ in range(tate):
    print("D", end="")

#二週目
print("D", end="")
for _ in range(yoko + 1):
    print("R", end="")
for _ in range(tate + 1):
    print("U", end="")
print("L", end="")
#二週半
print("U", end="")
for _ in range(yoko + 1):
    print("L", end="")
for _ in range(tate + 1):
    print("D", end="")
print("R", end="")

