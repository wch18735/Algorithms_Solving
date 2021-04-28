N = int(input())

origin_li = list(map(int, input().split(' ')))
li = set(origin_li.copy())
li = list(li)
li.sort(key=lambda x:x)

pressed_dict = {integer:idx for idx, integer in enumerate(li)}

for i in origin_li:
    print(pressed_dict.get(i), end=' ')
