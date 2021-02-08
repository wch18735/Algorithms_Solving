N = int(input())
creator = 1
creator_list = []

while True:
    # Creator 가 N에 도달하면 끝
    # N 보다 큰 수는 절대로 N의 Creator가 될 수 없음
    # 탈출 조건은 항상 가장 위에 쓰는 것이 좋음
    # 탈출 조건의 위치에 따라 오답이 나올 수 있음
    if creator == N:
        break

    temp_creator = creator
    decomposition_sum = 0
    decomposition_sum += temp_creator

    while temp_creator != 0:
        decomposition_sum += temp_creator % 10
        temp_creator = temp_creator//10

    if decomposition_sum == N:
        creator_list.append(creator)
        break

    creator += 1

if len(creator_list) == 0:
    print(0)
else:
    print(min(creator_list))