from bisect import bisect_left, bisect_right
from sys import stdin

if __name__=="__main__":
    N, Q = map(int, input().split(' '))

    logs = []

    for i in range(N):
        LOG = stdin.readline().strip()
        times, level = LOG.split('#')

        # times to string
        times = str(times[0:4] + times[5:7] + times[8:10] + times[11:13] + times[14:16] + times[17:19])

        logs.append([times, int(level)])

    logs.sort(key=lambda x: x[0])

    stamps, levels = list(zip(*logs))
    len_stamps = len(stamps)

    for i in range(Q):
        QUERY = stdin.readline().strip()

        from_time, to_time, level = QUERY.split('#')

        level = int(level)
        from_time = str(from_time[0:4] + from_time[5:7] + from_time[8:10] + from_time[11:13] + from_time[14:16] + from_time[17:19])
        to_time = str(to_time[0:4] + to_time[5:7] + to_time[8:10] + to_time[11:13] + to_time[14:16] + to_time[17:19])

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