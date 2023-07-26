from random import randint as r

with open('in', 'w') as f:
    f.write("100000 100000\n")
    for _ in range(100000):
        f.write(f"{r(1, 1000000000)}\n")
    for _ in range(100000):
        a, b = r(1, 100000), r(1, 100000)
        if a > b:
            a, b = b, a

        f.write(f"{a} {b}\n")
