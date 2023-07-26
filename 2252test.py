import random

with open('in', 'w') as f:
    f.write("32000 100000\n")
    for _ in range(0, 100000):
        f.write(f"{random.randint(1, 32000)} {random.randint(1, 32000)}\n")
