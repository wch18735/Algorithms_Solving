str = input()

croatia=['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=','z=']

for ch in croatia:
    str = str.replace(ch,'1')

print(len(str))