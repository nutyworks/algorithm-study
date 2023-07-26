with open('in', 'w') as f:
    f.write("32000 31999\n")
    f.write('\n'.join(map(lambda x: f"{x[0]} {x[1]}", list(zip(list(range(32000, 1, -1)), list(range(31999, 0, -1)))))))

