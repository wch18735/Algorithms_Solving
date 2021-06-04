from bisect import bisect_left, bisect_right

if __name__=="__main__":
    N, Q = map(int, input().split(' '))

    logs = []

    for i in range(N):
        LOG = input()
        times, level = LOG.split('#')

        # times to string
        times = times.replace('-', '').replace(':', '').replace(' ', '')

        logs.append([times, int(level)])

    logs.sort(key=lambda x: x[0])

    stamps, levels = list(zip(*logs))
    len_stamps = len(stamps)

    for i in range(Q):
        QUERY = input()

        from_time, to_time, level = QUERY.split('#')

        level = int(level)
        from_time = from_time.replace('-', '').replace(':', '').replace(' ', '')
        to_time = to_time.replace('-', '').replace(':', '').replace(' ', '')

        if int(to_time) < int(stamps[0]):
            print(0)
            continue

        left_idx = bisect_left(stamps, from_time)
        right_idx = bisect_right(stamps, to_time)

        if left_idx == len_stamps:
            print(0)
            continue

        answer = 0
        for log_level in levels[left_idx:right_idx]:
            if level <= log_level:
                answer += 1

        print(answer)