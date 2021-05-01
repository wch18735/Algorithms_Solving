def solution(n, arr1, arr2):
    answer = []

    jido = [[' ' for i in range(len(arr1))] for j in range(len(arr1))]

    # first arr
    for y_idx, num in enumerate(arr1):
        x_idx = len(arr1) - 1

        while num != 0:
            if num % 2 != 0:
                jido[y_idx][x_idx] = '#'

            num = (num // 2)
            x_idx -= 1

    # second arr
    for y_idx, num in enumerate(arr2):
        x_idx = len(arr2) - 1

        while num != 0:
            if num % 2 != 0:
                jido[y_idx][x_idx] = '#'

            num = (num // 2)
            x_idx -= 1

    jido = [''.join(s) for s in jido]
    answer = jido
    return answer