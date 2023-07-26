from random import randint as r

with open('in', 'w') as f:
    f.write("1000 1000\n")
    for _ in range(1000):
        f.write(''.join(map(lambda _: str(0 if r(0, 999) < 216 else 1), [0] * 1000)) + '\n')
