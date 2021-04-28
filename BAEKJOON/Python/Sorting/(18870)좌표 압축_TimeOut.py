N = int(input())

origin_list = list(map(int, input().split(' ')))
li = list(set(origin_list.copy()))
li.sort(key=lambda x: x)

for i in origin_list:
    print(li.index(i), end=' ')