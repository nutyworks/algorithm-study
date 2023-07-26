from random import randint as r

with open('in', 'w') as f:
    n = r(1, 30)
    f.write(f"{n}\n")

    for _ in range(n):
        a = r(0, 100)
        l = r(0, 100)

        f.write(f"{a} {a+l}\n")

