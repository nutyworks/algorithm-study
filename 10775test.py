from random import randint as r

with open('in', 'w') as f:
    g, p = r(1, 100000), r(1, 100000)
    f.write(f"{g}\n{p}\n")
    for _ in range(p):
        g_i = r(1, g)
        f.write(f"{g_i}\n")
