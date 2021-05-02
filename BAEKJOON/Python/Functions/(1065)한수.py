def check_seq(num):
    n_list = []

    while num != 0:
        n_list.append(num % 10)
        num //= 10

    if len(n_list) <= 2:
        return True
    else:
        d = n_list[0] - n_list[1]

        for idx, n in enumerate(n_list):
            if idx < 2:
                continue

            if n_list[idx - 1] - n_list[idx] != d:
                return False

        return True

if __name__=="__main__":
    N = int(input())

    if N < 100:
        print(N)
    else:
        answer = 99
        for n in range(100, N+1):
            if check_seq(n):
                answer += 1

        print(answer)