import random

with open('in', 'w') as f:
    n = random.randint(1, 1000)
    m = random.randint(1, 100)

    f.write(f"{n} {m}\n")

    for _ in range(m):
        k = random.randint(0, 10)
        f.write(' '.join(map(str, [k] + list(map(lambda x: random.randint(1, n), [0] * k)))) + '\n')
