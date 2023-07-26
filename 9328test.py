import random
from random import randint as r

digits = list(map(chr, [*range(ord('A'), ord('Z') + 1), *range(ord('a'), ord('z') + 1)])) + (['.', '*'] * 3000) + ['$']
keys = list(map(chr, range(ord('a'), ord('z') + 1)))

with open('in', 'w') as f:
    f.write("100\n")

    for _ in range(100):
        f.write("100 100\n")
        for __ in range(100):
            f.write(''.join(map(lambda x: random.choice(digits), range(100))) + '\n')
        k = r(0, 26)
        if k == 0:
            f.write("0\n")
        else:
            random.shuffle(keys)
            f.write(''.join(keys[:k]) + '\n')
