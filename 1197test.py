import random

with open('in', 'w') as f:
    f.write("10000 100000\n")
    
    for i in range(1, 10000):
        f.write(f"{i} {i+1} 1000000\n")

    for i in range(1, 100000 - 9999 + 1):
        u = random.randint(1, 10000)
        v = random.randint(1, 10000)
        w = random.randint(-1000000, 1000000)

        f.write(f"{u} {v} {w}\n")
