T = int(input())

person_list = []
rank_list = []

for _ in range(T):
    height, weight = map(int, input().split())
    person_list.append((height,weight))

for i in range(T):
    count = 1
    x1, y1 = person_list[i]
    for j in range(T):
        if i != j:
            x2, y2 = person_list[j]
            if x1 < x2 and y1 < y2:
                count += 1

    rank_list.append(count)

for i in range(T):
    print(rank_list[i], end=' ')
    
# 자기 보다 덩치가 큰 사람 수 + 1 = 등수