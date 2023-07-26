import random
from random import randint as r

with open('in', 'w') as f:
    f.write("1000000 10000 10000\n")

    for _ in range(1000000):
        i = r(-2**63, 2**63-1)
        f.write(f"{i}\n")

    s = [1, 2] * 10000
    random.shuffle(s)

    for i in range(20000):
        a = s[i]
        if a == 1:
            b, c = r(1, 1000000), r(-2**63, 2**63-1)
            f.write(f"{a} {b} {c}\n")
        else:
            b, c = r(1, 1000000), r(1, 1000000)
            if b > c:
                b, c = c, b
            f.write(f"{a} {b} {c}\n")
