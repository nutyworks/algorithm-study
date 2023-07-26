import random

for i in range(81):
    print(random.randint(1, 9) if random.randint(0, 5) == 1 else 0, end=' ')
