from collections import deque

def dfs(idx):
    global num_list, distance, route, answer, answer_route, distance, DP

    if idx == len(num_list):
        if answer > distance:
            answer = distance
            answer_route = list(route)
        return

    # check position and distances
    # add car1 state
    distance += abs(car1[0] - num_list[idx][0]) + abs(car1[1] - num_list[idx][1])
    route.append(1)

    if distance < DP[idx]:
        # change car position
        origin_x, origin_y = car1[0], car1[1]
        car1[0], car1[1] = num_list[idx][0], num_list[idx][1]
        dfs(idx + 1)
        car1[0], car1[1] = origin_x, origin_y

        # check distance at the idx
        DP[idx] = distance

    # change to origin
    distance -= abs(car1[0] - num_list[idx][0]) + abs(car1[1] - num_list[idx][1])
    route.pop()

    # add current state
    distance += abs(car2[0] - num_list[idx][0]) + abs(car2[1] - num_list[idx][1])
    route.append(2)

    if distance < DP[idx]:
        # change car position
        origin_x, origin_y = car2[0], car2[1]
        car2[0], car2[1] = num_list[idx][0], num_list[idx][1]
        dfs(idx + 1)
        car2[0], car2[1] = origin_x, origin_y

        # check distance at the idx
        DP[idx] = distance

    # change to origin
    distance -= abs(car2[0] - num_list[idx][0]) + abs(car2[1] - num_list[idx][1])
    route.pop()

def solution():
    global num_list, car1, car2, distance, route, answer, answer_route, DP

    N = int(input())

    W = int(input())

    num_list = []
    DP = [float('inf') for i in range(W)]
    for _ in range(W):
        a, b = map(int, input().split(' '))
        num_list.append((a, b))

    # car positions
    car1 = [1, 1]
    car2 = [N, N]

    # total distance and route
    distance = 0
    route = deque()

    # answers
    answer = 12345678910
    answer_route = []

    # search
    dfs(0)

    # print answer
    print(answer)
    for i in answer_route:
        print(i)

if __name__ == "__main__":
    solution()