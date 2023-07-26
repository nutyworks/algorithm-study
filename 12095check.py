import sys

lines = ""
for line in sys.stdin:
    lines += line

print(lines)
print(list(map(lambda x: lines.split("\n\n")[1].split("cnt")[0].count(str(x)), range(1, 10))))
