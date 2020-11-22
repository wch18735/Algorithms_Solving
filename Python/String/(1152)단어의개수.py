str = input()
str = str.strip().split(' ')
if len(str) == 1:
    if str[0] == '':
        print(0)
    else: print(len(str))
else:
    print(len(str))