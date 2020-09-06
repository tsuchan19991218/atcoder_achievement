s = input()
first = -1
end = 0
i = 0
for c in s:
    if first == -1 and c == 'A':
        first = i
    if c == "Z":
        end = i
    i += 1
print(end - first + 1)