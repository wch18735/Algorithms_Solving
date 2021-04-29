N, X = map(int, input().split(' '))

li = list(map(int, input().split(' ')))

cnt = 0
for i in li:
    if X > i:
        print(i, end=' ')