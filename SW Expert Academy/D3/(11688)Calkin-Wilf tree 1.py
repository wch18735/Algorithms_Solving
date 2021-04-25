T = int(input())

for test_case in range(1, T+1):
    # path
    path_list = list(input())

    # 노드
    node = [1, 1]

    for ch in path_list:
        if ch == 'L':
            node[1] = node[0] + node[1]
        elif ch == 'R':
            node[0] = node[0] + node[1]

    print('#' + str(test_case) + ' ' + str(node[0]) + ' ' + str(node[1]))