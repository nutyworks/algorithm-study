import os, io, sys, collections

input = list(map(bytes.decode, io.BytesIO(os.read(0, os.fstat(0).st_size)).readlines()))
q = collections.deque(input[0].rstrip(), maxlen=600001)
q.appendleft('|')

cursor = 0

for line in map(str.split, map(str.rstrip, input[2:])):
    if line[0] == 'L':
        if q[-1] != '|':
            q.appendleft(q.pop())
            cursor += 1
    elif line[0] == 'D':
        if q[0] != '|':
            q.append(q.popleft())
            cursor -= 1
    elif line[0] == 'B':
        if q[-1] != '|':
            q.pop()
    else:
        q.append(line[1])

c = ''.join(q)

sys.stdout.write(c[cursor+1:] + c[:cursor] + '\n')