import random

with open('in', 'w') as f:
    f.write("100000 1000000\n")

    for i in range(1, 100000):
        f.write(f"{i} {i + 1} 1000\n")

    for i in range(900001):
        u, v, w = random.randint(1, 100000), random.randint(1, 100000), random.randint(1, 999)
        f.write(f"{u} {v} {w}\n")
