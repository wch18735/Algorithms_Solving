from math import floor

def successor(arr, t):
    # target 과 같거나, target 보다 큰 가장 작은 정수의 index 반환
    L = 0
    R = len(arr)

    while L < R:
        M = floor((L + R) / 2)

        # right most -> 기본 가정 상황에서 arr[M] == target 일 때 L이 움직여야 함
        # L이 이동하는 상황은 arr[M] < target
        # 여기에 등호 붙여줌
        if arr[M] <= t:
            L = M + 1
        else:
            R = M

    if R == 0:
        return 0
    if arr[R-1] == t:
        return R - 1
    else:
        return R


if __name__=="__main__":
    N = int(input())

    arr = list(map(int, input().split(' ')))

    max_len_arr = [arr[0]]

    for i in range(N):
        if max_len_arr[-1] < arr[i]:
            max_len_arr += [arr[i]]
        elif max_len_arr[-1] == arr[i]:
            continue
        else:
            rm = successor(max_len_arr, arr[i])
            max_len_arr[rm] = arr[i]

    print(len(max_len_arr))