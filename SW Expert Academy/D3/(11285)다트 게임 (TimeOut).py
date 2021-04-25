# 입력
T = int(input())

# 반지름 리스트
radius_list = [(20 * i)**2 for i in range(1, 11)]

for test_case in range(1, T+1):
    dart_num = int(input())

    result = 0

    for _ in range(dart_num):
        x_pos, y_pos = map(int, input().split(' '))

        # 다트와 원점 사이 거리
        distance_r = x_pos**2 + y_pos**2

        if distance_r > radius_list[-1]:
            continue

        for r_idx, r in enumerate(radius_list):
            if distance_r <= r:
                result += (10 - r_idx)
                break

    print('#' + str(test_case) + ' ' + str(result))