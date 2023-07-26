import random

with open('in', 'w') as f:
    f.write("2000\n");

    # f.write(' '.join(list(map(lambda x: str(random.randint(1, 100000)), [0] * 2000))) + '\n')
    f.write(' '.join(map(str, list(range(1, 1001)) + list(range(1000, 0, -1)))) + '\n')
    
    f.write("1000000\n")

    for _ in range(1000000):
        a, b = random.randint(1, 2001), random.randint(1, 2001)

        if random.randint(1, 4) == 1:
            b = 2001 - a

        if a > b:
            a, b = b, a

        f.write(f"{a} {b}\n")
